class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        for(int i=0;i<k;i++){
            while(!dq.empty()&&nums[dq.front()]<=nums[i])dq.pop_front();
            dq.push_front(i);
             
        }
        vector<int>ans;
        ans.push_back(nums[dq.back()]);
        for(int i=k;i<nums.size();i++){
          if(i-dq.back()>=k)dq.pop_back();
          while(!dq.empty()&&nums[dq.front()]<=nums[i])dq.pop_front();
            dq.push_front(i);
            ans.push_back(nums[dq.back()]);
        }
return ans;
    }
};