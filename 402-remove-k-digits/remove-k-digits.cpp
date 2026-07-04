class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        for(int i=0;i<num.size();i++){
            while(!st.empty()&&st.top()>num[i]&&k>0){
                st.pop();
               k--;
   
            }
            st.push(num[i]);
        }
        string ans="";

        while(!st.empty()&&k>0){
            st.pop();
            k--;
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        int ii=-1;
        for(int i=0;i<ans.size();i++){
            if(ans[i]!='0'){
              ii=i;
              break;
            }
        }
        if(ans.empty()||ii==-1)
    return "0";
        string s=ans.substr(ii);
        return s;
    }

};