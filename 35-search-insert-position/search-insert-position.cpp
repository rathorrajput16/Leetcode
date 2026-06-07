class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int indx=upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        int indx1=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        if(indx1<n&&nums[indx1]==target)return indx1;
        return indx;
    }
};