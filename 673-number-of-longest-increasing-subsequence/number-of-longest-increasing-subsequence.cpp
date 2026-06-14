class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int maxi=0;
        int n=nums.size();
        vector<int>count(n,1);
        vector<int>dp(n,1);
        for(int i=0;i<n;i++){
           for(int j=0;j<i;j++){
            if(nums[i]>nums[j]){
                if(dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    count[i] = count[j];
                }
                else if(dp[i]==dp[j]+1){
                    count[i]+=count[j];
                }
            }
           }
        }
        for(int i=0;i<n;i++){
            maxi=max(maxi,dp[i]);
        }
        int sum=0;
        for(int i=0;i<n;i++){
            if(dp[i]==maxi){
                sum+=count[i];
            }
        }
        return sum;
    }
};