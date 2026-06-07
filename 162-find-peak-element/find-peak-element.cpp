class Solution {
    using ll=long long;
public:
    int findPeakElement(vector<int>& nums) {
        ll low=1;
        ll high=nums.size()-2;
        ll n=nums.size();
        if(n==1)return 0;
        if(nums[0]>nums[1])return 0;
        if(nums[n-1]>nums[n-2])return n-1;
        while(low<=high){
            ll mid=low+(high-low)/2;
            if(nums[mid]>nums[mid+1]&&nums[mid]>nums[mid-1])return mid;
            if(nums[mid]>nums[mid-1]&&nums[mid+1]>nums[mid]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return -1;
    }
};