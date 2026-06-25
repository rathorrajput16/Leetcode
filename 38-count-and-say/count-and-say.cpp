class Solution {
public:
    string f(int i,int n,string ans){
        if(i==n){
         return ans;    
        }
        string res="";
        char last=ans[0];
        int cnt=1;
        for(int i=1;i<ans.size();i++){
          if(last==ans[i]){
            cnt++;

          }
          else{
            res+=to_string(cnt);
            res+=last;
            last=ans[i];
            cnt=1;
          }
        }    
        res+=to_string(cnt);
            res+=last;
        return f(i+1,n,res);

    }
    string countAndSay(int n) {
      if(n==1){
        return "1";
      }
      string ans="1";
      return f(1,n,ans);
      
    }
};