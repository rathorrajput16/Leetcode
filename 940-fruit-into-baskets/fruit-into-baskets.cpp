class Solution {
    using ll=long long;
public:
    int totalFruit(vector<int>& fruits) {
        int ans=0;
        int left=0;
        map<ll,ll>mp;
        for(int i=0;i<fruits.size();i++){
        mp[fruits[i]]=i;
        if(mp.size()>2){
            vector<pair<ll,ll>>v;
            for(auto it:mp){
                v.push_back({it.second,it.first});
            }
            sort(v.begin(),v.end());
            left=v[0].first+1;
            mp.erase(v[0].second);
        }
            
            ans=max(ans,i-left+1);
        }
        return ans;
    }
};