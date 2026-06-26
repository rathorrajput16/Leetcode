class Solution {
    using ll=long long;
public:
    string minWindow(string s, string t) {
        map<char,ll>mp;
        for(char ch:t){
            mp[ch]++;
        }
        int needed=0,left=0,start=0,ans=1e9;
        for(int i=0;i<s.size();i++){
            if(mp[s[i]]>0){    
                needed++;
            }
            mp[s[i]]--;
            while(needed==t.size()){
                if(i-left+1<ans){
                    start=left;
                    ans=i-left+1;
                }
                 mp[s[left]]++;
                 
                 if(mp[s[left]]>0){
                    needed--;
                 }
                 left++;
        }
        }
        if (ans == 1e9)
    return "";
        string ans1=s.substr(start,ans);
        return ans1;
    }
};