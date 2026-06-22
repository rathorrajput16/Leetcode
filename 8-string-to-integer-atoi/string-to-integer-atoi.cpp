class Solution {
public:
    int myAtoi(string s) {
       bool neg=false;
       int ind=0;
       while(ind<s.size()&&s[ind]==' ')ind++;
       if(s[ind]=='-'){
        neg=true;
        ind++;
       }
       if(s[ind]=='+'&&!neg){
          ind++;
       }
       long long num=0;
       long long val=pow(2,31);
       while(ind<s.size()&&s[ind]>='0'&&s[ind]<='9'){
                 num=num*10+(s[ind]-'0'); 
                 if(neg&&num>val)return INT_MIN;
                 if(!neg&&num>INT_MAX)return INT_MAX;  
                 ind++;
       }
       if(neg)num=num*(-1);
       return num;
    }
};