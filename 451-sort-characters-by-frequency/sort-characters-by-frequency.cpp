class Solution {
public:
    static bool comp(pair<char,int>&a,pair<char,int>&b){
        if(a.second==b.second){
            return a.first<b.first;
        }
        return a.second>b.second;
    }
    string frequencySort(string s) {
        map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        vector<pair<char,int>>v(mp.begin(),mp.end());;
        
        sort(v.begin(),v.end(),comp);
            string l;
        for(int i=0;i<v.size();i++){
          while(v[i].second--){
            l+=v[i].first;
          }
        }
        return l;
    }
};