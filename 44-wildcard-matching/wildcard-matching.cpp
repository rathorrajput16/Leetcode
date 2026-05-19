class Solution {
public:
    bool isMatch(string s, string p) {
            string str=p;
         int m=str.size();
        int n=s.size();
     vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));
     for(int i=0;i<=m;i++)dp[0][i]=false;
     for(int i=0;i<=n;i++)dp[i][0]=false;
     dp[0][0]=true;
        for (int j = 1; j <= m; j++) {
            bool allStar = true;

            for (int k = 1; k <= j; k++) {
                if (p[k - 1] != '*') {
                    allStar = false;
                    break;
                }
            }

            dp[0][j] = allStar;
        }     
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==str[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(str[j-1]=='?'){
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(str[j-1]=='*'){
                     dp[i][j]=dp[i][j - 1]||dp[i - 1][j];
                }
                

            }
        }  
        return dp[n][m];
    }
};