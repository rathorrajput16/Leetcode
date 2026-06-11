class Solution {
public:
    double f(double x, long long n){
         double res=1;
         while(n>0){
            if(n%2){
               res=res*x;
               n=n-1;
            }
            else{
               x=x*x;
                n=n/2;
               
            }
           
         }
       return res;
    }
    double myPow(double x, int n) {
        if(n<0)x=1/x;
         long long nn=n;
        return f(x,abs(nn));
    }
};