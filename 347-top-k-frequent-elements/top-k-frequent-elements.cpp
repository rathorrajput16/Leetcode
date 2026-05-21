class Solution {
  using ll=long long;
public:

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<ll,ll>mp;
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
         for(auto i:nums){
            mp[i]++;
         }
         for(auto it:mp){
            pq.push({it.second,it.first});
            if(pq.size()>k)pq.pop();
         }
         vector<int>res;
         while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
         }
         return res;
    }
};