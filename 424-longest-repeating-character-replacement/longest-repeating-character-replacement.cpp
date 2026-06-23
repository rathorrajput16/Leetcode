class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char,int>mp;
        int left=0,ans=0,maxi=0;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
            maxi=max(maxi,mp[s[i]]);
            while((i-left+1)-maxi>k){
                mp[s[left]]--;
                left++;
                
            }
            ans=max(ans,i-left+1);
        }
        return ans;
    }
};