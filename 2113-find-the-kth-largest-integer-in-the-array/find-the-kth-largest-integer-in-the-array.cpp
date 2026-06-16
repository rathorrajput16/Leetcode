class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
       
    vector<vector<string>>ans(101);
    for(int i=0;i<nums.size();i++){
        ans[nums[i].size()].push_back(nums[i]);
    }
    int val=k;
     for(int i=100;i>=0;i--){
        sort(ans[i].rbegin(),ans[i].rend());
        if(ans[i].size()>=val){
            return ans[i][val-1];
        }
        else{
            val-=ans[i].size();
        }
    }
    return "ayush";
    }
};