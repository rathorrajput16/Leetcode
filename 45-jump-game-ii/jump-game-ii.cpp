class Solution {
public:
    int jump(vector<int>& nums) {
         int ans=0;
         int maxi=0;
         int currmaxi=0;
        for(int i=0;i<nums.size();i++){
           if(maxi>=i){
           
           }
           else{
            maxi=currmaxi;
            ans++;
           }
            currmaxi=max(currmaxi,i+nums[i]);
        }
        return ans;
    }
};