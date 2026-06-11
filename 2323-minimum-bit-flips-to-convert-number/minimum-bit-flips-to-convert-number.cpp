class Solution {
public:
    string bs(int n){
        string ans="";
         while(n>0){
            ans+=to_string(n%2);
            n=n/2;
         }
         return ans;
    }

    int minBitFlips(int start, int goal) {
        string s=bs(start);
        string e=bs(goal);
        if(s.size()>e.size()){
            while(e.size()!=s.size()){
                e+='0';
            }
            reverse(s.begin(),s.end());
            reverse(e.begin(),e.end());
        }
        if(s.size()<e.size()){
            while(e.size()!=s.size()){
                s+='0';
            }
            reverse(s.begin(),s.end());
            reverse(e.begin(),e.end());
        }
        int cnt=0;
        for(int i=0;i<s.size();i++){
            if(s[i]!=e[i])cnt++;
        }
        return cnt;
    }
};