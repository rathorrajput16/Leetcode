class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int cnt=0;
        int left=0;
        int ans=0;
        for(int right=0;right<nums.size();right++){
                if(nums[right]==0)cnt++;
                
                if(cnt<=k){
                   if(ans<right-left+1){
                    ans=right-left+1;
                   }
                }
                if(cnt>k){
                   while(nums[left]!=0){
                     left++;
                   }
                   cnt--;
                   left++;
                    if(ans<right-left+1){
                    ans=right-left+1;
                   }
                }

        }
   return ans;
    }
};