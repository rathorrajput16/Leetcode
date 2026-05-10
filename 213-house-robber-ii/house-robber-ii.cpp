class Solution {
public:
  int f(vector<int>& nums){
      int n=nums.size();
      if(n==0)return 0;
        if(n==1)return nums[0];
        
        vector<long long>dp(n,0);
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            dp[i]=max(dp[i-1],dp[i-2]+1LL*nums[i]);
        }
        return dp[n-1];
  }
    int rob(vector<int>& nums) {
        vector<int>temp;
          int n=nums.size();
      if(n==0)return 0;
        if(n==1)return nums[0];
        vector<int>temp1;
        for(int i=1;i<nums.size();i++){
            temp.push_back(nums[i]);
        }
        for(int i=0;i<nums.size()-1;i++){
            temp1.push_back(nums[i]);
        }
        return max(f(temp),f(temp1));
    }
};