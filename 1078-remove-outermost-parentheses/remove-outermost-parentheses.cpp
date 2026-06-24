class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";
        string valid="";
        int sum=0;
        for(int i=0;i<s.size();i++){
             if(sum==0&&s[i]=='('){
                ans="";
                sum++;
             }
             else if(sum==1&&s[i]==')'){
                valid+=ans;
                sum--;
             }
             else if(s[i]=='('){
                ans+=s[i];
                sum++;
             }
             else{
                ans+=s[i];
                sum--;
             }
        }
        return valid;
    }
};