class Solution {
public:
   
  
    int f(int i,string& s,vector<vector<int>>&dp,vector<int> &memo){
        if(s.size()==i){
            return 0;
        }
        if(memo[i]!=-1)return memo[i];
        int mini=INT_MAX;
        for(int j=i;j<s.size();j++){
            if(dp[i][j]){
                mini=min(mini,1+f(j+1,s,dp,memo));
            }
        }
        return memo[i]=mini;
    }
    int minCut(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,false));
        for(int i=0;i<n;i++){
            dp[i][i]=true;
        }
        for(int i=0;i<n-1;i++){
          if(s[i]==s[i+1])dp[i][i+1]=true;
          else dp[i][i+1]=false;
        }
        for(int len=3;len<=n;len++){
            for(int i=0;i+len-1<n;i++){
                int j=i+len-1;
                if(s[i]==s[j]&&dp[i+1][j-1])dp[i][j]=true;
            }
        }
        vector<int> memo(n, -1);
        return f(0,s,dp,memo)-1;
    }
};