class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int>dp(nums.size(),1e9);
        dp[0]=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            int val=min(n-1,i+nums[i]);
            for(int j=i+1;j<=val;j++){
                dp[j]=min(dp[j],1+dp[i]);
            }
        }
        return dp[n-1];
    }
};