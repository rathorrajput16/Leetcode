class Solution {
    using ll=long long;
public:
    string minWindow(string s, string t) {
        if(t.size()>s.size())return "";
        int start=-1;
        int minlen=1e9;
        int left=0;
        map<char,ll>mp;
        for(int i=0;i<t.size();i++){
             mp[t[i]]++;
          }
          int cnt=0;
        for(int i=0;i<s.size();i++){
            if(mp[s[i]]>0)cnt++;
            mp[s[i]]--;
            if(cnt==t.size()){
                while(cnt==t.size()){
                    if(minlen>i-left+1){
                        minlen=i-left+1;
                        start=left;
                    }
                    if(mp[s[left]]==0)cnt--;
                    mp[s[left]]++;
                    left++;
                }
            }
        }
       if(start==-1) return "";
        return s.substr(start,minlen);
    }
};