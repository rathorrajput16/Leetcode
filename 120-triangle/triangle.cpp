class Solution {
public:
    int minsum(vector<vector<int>>& triangle,int i ,int j,vector<vector<int>>&dp){
        int n = triangle.size();

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        if(i==n-1){
            return triangle[n-1][j];
        }
       int d=triangle[i][j]+minsum(triangle,i+1,j,dp);
        int d1=triangle[i][j]+minsum(triangle,i+1,j+1,dp);
        return dp[i][j]=min(d,d1);
    }


     
    int minimumTotal(vector<vector<int>>& triangle) {
          int n = triangle.size();

       vector<vector<int>>dp(n,vector<int>(n,1e9));
       dp[0][0]=triangle[0][0];
       for(int i=0;i<n-1;i++){
        for(int j=0;j<i+1;j++){
             dp[i+1][j]=min(dp[i][j]+triangle[i+1][j],dp[i+1][j]);
             dp[i+1][j+1]=min(dp[i][j]+triangle[i+1][j+1],dp[i+1][j+1]);
        }
       }
       int ans=1e9;
       for(int j=0;j<n;j++){
         if(dp[n-1][j]<ans){
            ans=dp[n-1][j];
         }
         }
       return ans;

    }
};