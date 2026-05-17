class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        using ll=long long;
        unordered_map<ll,ll>mp;
        set<ll>st;
        ll left=0;
        ll ans=0;
        int n=fruits.size();
        for(ll i=0;i<n;i++){
         mp[fruits[i]]=i;
         if(st.size()==2&&st.find(fruits[i])==st.end()){
            ll val=fruits[i];
            ll mini=1e9;
            ll maxi=-1;
            for(auto it:st){
                maxi=max(maxi,mp[it]);
                mini=min(mini,mp[it]);
            }
            left=mini+1;
            ll val2=fruits[mini];
            st.erase(val2);

         }
         st.insert(fruits[i]);
         ans=max(i-left+1,ans);
         }
        
         return ans;
    }
};