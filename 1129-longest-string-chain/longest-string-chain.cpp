class Solution {
    using ll=long long;
public:
    bool check(string s,string t){
        int i=0,j=0;
        if(t.size()+1!=s.size())return false;
         while (i < s.size()) {
            if (j < t.size() && s[i] == t[j]) {
                i++;
                j++;
            }
            else {
                i++;
            }
        }

        return j==t.size();
    }
    int longestStrChain(vector<string>& words) {
        ll n=words.size();
        vector<ll>dp(n,1);
       ll ans=0;
             sort(words.begin(), words.end(),
             [](string &a, string &b) {
                return a.size() < b.size();
             });
        for(ll i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
               if(check(words[i],words[prev])){
                    dp[i] = max(dp[i], 1 + dp[prev]);
               }

            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};