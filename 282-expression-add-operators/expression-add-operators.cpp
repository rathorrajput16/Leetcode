class Solution {
 using ll=long long;
public:
 
   vector<string>ans;
    void f(ll indx,string s,ll target,string res,ll eval,ll last){
        if(indx==s.size()&&eval==target){
            ans.push_back(res);
        }
        if(indx==s.size())return;
        for(ll i=indx;i<s.size();i++){
             if (i != indx && s[indx] == '0') break;
              string part=s.substr(indx,i-indx+1);
              long long val=stoll(part);
              if(indx==0){
                
                 f(i+1,s,target,part,val,val);
              }
              else{
                 f(i+1,s,target,res+'+'+part,eval+val,val);
                 f(i+1,s,target,res+'-'+part,eval-val,-val);
                 f(i+1,s,target,res+'*'+part,eval-last+last*val,last*val);
              }
        }
    }
    vector<string> addOperators(string num, int target) {
        string res="";
         ll indx=0;
         ll eval=0;
         ll last=0;
        f(indx,num,(long long)target,res,eval,last);
        return ans;
    }
};