class Solution {
    using ll=long long;
public:
    vector<int> singleNumber(vector<int>& nums) {
        if(nums.size()==2)return nums;
        ll num=0;
        for(ll i=0;i<nums.size();i++){
            num^=nums[i];
        }
        
        ll setbit = num & (-num);
        int xor1=0,xor2=0;
          for(ll i=0;i<nums.size();i++){
           if(nums[i]&setbit){
              xor1=xor1^nums[i];
           }
           else{
              xor2=xor2^nums[i];
           }
        }
        return {xor1,xor2};
    }
};