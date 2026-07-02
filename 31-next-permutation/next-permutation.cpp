class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index=-1;
        int n=nums.size();
        for(int i=nums.size()-1;i>0;i--){
           if(nums[i-1]<nums[i]){
                  index=i-1;
                  break;
           }
        }
        if(index==-1){
            reverse(nums.begin(),nums.end());
            return;
    }
      for(int i=n-1;i>index;i--){
        if(nums[index]<nums[i]){
            swap(nums[index],nums[i]);
            reverse(nums.begin()+index+1,nums.end());
            break;
        }
      }
      return;
    }
};