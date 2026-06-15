class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int l=1;
        int r=1;
        int ans=nums[0];
         int n=nums.size();
        for(int i=0;i<n;i++){
         l*=nums[i];
         r*=nums[n-i-1];
         ans=max({l,r,ans});
         if(l==0)l=1;
         if(r==0)r=1;
        }
        return ans;
    }
};