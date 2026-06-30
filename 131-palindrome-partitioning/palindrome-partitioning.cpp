class Solution {
public:
    vector<vector<string>>ans;
    bool ispallindrome(string s){
        int low=0;
        int high=s.size()-1;
        while(low<=high){
            if(s[low]!=s[high]){
             return false;
            }
            low++;
            high--;
        }
        return true;
    }
    void f(int ind,vector<string>&res,string s){
        if(ind==s.size()){
            ans.push_back(res);
            return;
        }
        for(int i=ind;i<s.size();i++){
            if(ispallindrome(s.substr(ind,i-ind+1))){
                res.push_back(s.substr(ind,i-ind+1));
                f(i+1,res,s);
                res.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
      vector<string>res;
       f(0,res,s);
        return ans;
    }
};