class Solution {
public:
    int numDistinct(string s, string t) {
      const long long mod=1e13+7;

        string str=t;
      
        int m=str.size();
        int n=s.size();
     vector<vector<int>>dp(n+1,vector<int>(m+1,0));
     for(int i=0;i<=n;i++)dp[i][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==str[j-1]){
                    dp[i][j]=(dp[i-1][j]+dp[i-1][j-1]%mod);
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }  
     
      
         return dp[n][m];  
    }
};