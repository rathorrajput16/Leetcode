class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>vis(256,-1);
        int left=0;
        int ans=0;
        for(int right=0;right<s.size();right++){
                 if(vis[s[right]]<left){
                    vis[s[right]]=right;
                 }
                 else{
                    if(right-left>ans)ans=right-left;
                    left=vis[s[right]]+1;
                     vis[s[right]]=right;
                     
                 }

        }
         if(s.size()-left>ans)ans=s.size()-left;
         return ans;
    }
};