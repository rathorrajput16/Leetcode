class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int>mp;
        for(int i=0;i<t.size();i++){
            mp[t[i]]++;
        }
        int needed=t.size();
        int left=0;
        int start=0;
        int ans=1e9;
        for(int i=0;i<s.size();i++){
              if(mp[s[i]]>0){
                
                needed--;
              }
              mp[s[i]]--;
              while(needed==0){
               if(i-left+1<ans){
                start=left;
                ans=i-left+1;
               }
               if(mp[s[left]]==0){
                needed++;
               }
               
               mp[s[left]]++;
               left++;

              }
        }
        if(ans == 1e9) return "";
        return s.substr(start,ans);
    }
};