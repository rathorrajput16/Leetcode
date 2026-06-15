class Solution {
public:
    int start=0;
    int maxlen=1;
    void expand(int left,int right,string s){
        int n=s.size();
        int cnt=0;
        while(left>=0&&right<n){
            if(left==right)cnt++;
            else if(s[left]==s[right]){
                cnt+=2;
            }
            else{
                break;
            }
            left--;
            right++;
        }
        if(maxlen<cnt){
            maxlen=cnt;
            start=left+1;
        }
    }
    string longestPalindrome(string s) {
        int n=s.size();
        for(int i=0;i<n;i++){
            expand(i,i,s);
            expand(i,i+1,s);
        }
        return s.substr(start,maxlen);
    }
};