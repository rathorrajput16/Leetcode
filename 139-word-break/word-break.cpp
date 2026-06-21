class Solution {
public:
    unordered_set<string>st;
    vector<int>dp;
    bool f(int ind,string s){
        if(ind==s.size()){
            return true;
        }
        if(dp[ind]!=-1)return dp[ind];
        for(int i=ind;i<s.size();i++){
            if(st.find(s.substr(ind,i-ind+1))!=st.end()){
                if(f(i+1,s))return dp[ind]=true;
            }
        }
        return dp[ind]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
         for(int i=0;i<wordDict.size();i++){
            st.insert(wordDict[i]);
         }
         int n=s.size();
         dp.resize(n,-1);
         return f(0,s);
    }
};