class Solution {
public:
vector<vector<string>>ans;
    bool ispalindrome(string s){
        int low=0;
        int high=s.size()-1;
        while(low<=high){
            if(s[low]==s[high]){
                low++;
                high--;
            }
            else{
                return false;
            }
        }
        return true;
    }
     void f(int ind,vector<string>&path,string s){
        if(ind==s.size()){
            ans.push_back(path);
            return;
        }
        for(int i=ind;i<s.size();i++){
            if(ispalindrome(s.substr(ind,i-ind+1))){
                path.push_back(s.substr(ind,i-ind+1));
                f(i+1,path,s);

                path.pop_back();
            }
        }
     }
    vector<vector<string>> partition(string s) {
            vector<string>path;
            f(0,path,s);
            return ans;
    }
};