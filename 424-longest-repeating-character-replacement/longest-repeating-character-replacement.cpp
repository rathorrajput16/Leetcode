class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0;
        map<char,int>mp;
        int ans=0;int maxfreq=0;

        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
         maxfreq=max(maxfreq,mp[s[i]]);
           while((i-left+1)-maxfreq>k){
            mp[s[left]]--;
            left++;
           }
                   
            
            ans=max(ans,i-left+1);
        }
        return ans;
    }
};