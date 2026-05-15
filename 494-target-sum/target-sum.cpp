class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        
    
        sort(nums.begin(),nums.end());
        int sum=accumulate(nums.begin(),nums.end(),0);
        if((target +sum)<0||(target+sum)%2) return 0;
        target=(target+sum)/2;
        vector<vector<int>>dp(n,vector<int>(target+1,0));
        if(nums[0]==0)dp[0][0]=2;
        else {
            dp[0][0]=1;
            if(nums[0]<=target)dp[0][nums[0]]=1;
        }

        for(int i=1;i<n;i++){
             for(int j=0;j<=target;j++){
                int nottake=dp[i-1][j];
                int take=0;
                if(j>=nums[i]){
                    take=dp[i-1][j-nums[i]];
                }
                dp[i][j]=take+nottake;
             }
        }
        return dp[n-1][target];
    }
};