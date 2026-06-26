class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int cnt=0;
        int ans=0;
        int left=0;
        for(int i=0;i<nums.size();i++){
              if(nums[i]==0)cnt++;
              if(cnt>k){
                while(cnt>k){
                    if(nums[left]==0)cnt--;
                    left++;
                    
                }
              }
              ans=max(ans,i-left+1);
        }
        return ans;
    }
};