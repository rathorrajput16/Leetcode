class Solution {
public:
     const long long mod = 1e9 + 7;
    vector<long long> fact, invFact;

    long long power(long long base, long long exp) {
        long long ans = 1;

        while (exp > 0) {
            if (exp & 1) {
                ans = (ans * base) % mod;
            }

            base = (base * base) % mod;
            exp >>= 1;
        }

        return ans;
    }
    
   
    int countAnagrams(string s) {
      int n = s.size();
        fact.assign(n + 1, 1);
        invFact.assign(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            fact[i] = (fact[i - 1] * i) % mod;
        }
        invFact[n] = power(fact[n], mod - 2);
        for (int i = n - 1; i >= 0; i--) {
            invFact[i] = (invFact[i + 1] * (i + 1)) % mod;
        }
        vector<int>freq(26,0);
        vector<int>res;
        int cnt=0;
        long long ans=1;
        for(int i=0;i<s.size();i++){
           if(s[i]==' '){
              int val=fact[cnt];
              for(int i=0;i<26;i++){
                if(freq[i]==0)continue;
                val=(val*invFact[freq[i]])%mod;
                freq[i]=0;
              }
              ans=(ans*val)%mod;
              cnt=0;
           }
           else{
              cnt++;
              freq[s[i]-'a']++;
           }
           
         }
        int val=fact[cnt];
              for(int i=0;i<26;i++){
                if(freq[i]==0)continue;

                val=(val*invFact[freq[i]])%mod;
                freq[i]=0;
              }
              ans=(ans*val)%mod;
              return ans;
    }

};