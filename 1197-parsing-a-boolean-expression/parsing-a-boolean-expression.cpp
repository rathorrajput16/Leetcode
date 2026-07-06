class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char>st;
        string s=expression;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('||s[i]==','){
              continue; 
            }
            if(s[i]!=')'){
             st.push(s[i]);
            }
            else{
                int t=0,f=0;
                while(!st.empty()&&(st.top()=='t'||st.top()=='f')){
                    if (st.top() == 't')
                        t++;
                    else
                        f++;
                    st.pop();
                }
                 char op = st.top();
                st.pop();
                if (op == '!') {
                    if (t == 1)
                        st.push('f');
                    else
                        st.push('t');
                }
                else if (op == '&') {
                    if (f > 0)
                        st.push('f');
                    else
                        st.push('t');
                }
                else { 
                    if (t > 0)
                        st.push('t');
                    else
                        st.push('f');
                }
            }
            }
           
        
      return st.top()=='t';
    }
};