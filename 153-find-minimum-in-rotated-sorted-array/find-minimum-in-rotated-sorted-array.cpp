class Solution {
using ll=long long;
public:
    int findMin(vector<int>& nums) {
        ll low=0;
        ll ans=1e9;
        ll high=nums.size()-1;
        while(low<=high){
            ll mid=low+(high-low)/2;
            if(nums[mid]<=nums[high]){
                ans=min((ll)nums[mid],ans);
                high=mid-1;
            }
            else{
              ans=min((ll)nums[low],ans);
              low=mid+1;
            }
        }
        return ans;
    }
};