class Solution {
public:
    bool canPartition(vector<int>& nums) {
      int sum=0;
      int n=nums.size();
      if(n==1)return false;
      for(int i=0;i<nums.size();i++)sum+=nums[i];
      if(sum%2)return false;
      int target=sum/2;
      vector<vector<bool>>dp(n,vector<bool>(sum+1,false));
      for(int i=0;i<n;i++){
        dp[i][0]=true;
      }
      dp[0][nums[0]]=true;
      for(int i=1;i<n;i++){
        for(int j=1;j<=target;j++){
            bool pick=false;
            if(j>=nums[i]){
                pick=dp[i-1][j-nums[i]];
            }
            dp[i][j]=pick||dp[i-1][j];
        }
      }
      return dp[n-1][target];
    }
};