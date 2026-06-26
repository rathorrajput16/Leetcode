class Solution {
public:
    unordered_map<char,int>mp;
    int ans=0;
    int left=0;
    int lengthOfLongestSubstring(string s) {
        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])==mp.end()){
                
            }
            else{
             if(mp[s[i]]<left){

             }
             else{
                left=mp[s[i]]+1;
             }
            }
            mp[s[i]]=i;
            ans=max(ans,i-left+1);
        }
        return ans;
    }
};