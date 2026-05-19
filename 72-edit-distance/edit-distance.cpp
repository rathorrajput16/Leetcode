class Solution {
public:
    int minDistance(string word1, string word2) {
        string s=word1,str=word2;
         int m=str.size();
        int n=s.size();
     vector<vector<int>>dp(n+1,vector<int>(m+1,0));
     for(int i=0;i<=n;i++)dp[i][0]=i;
     for(int i=0;i<=m;i++)dp[0][i]=i;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==str[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
                }
            }
        }  
        return dp[n][m];
    }
};