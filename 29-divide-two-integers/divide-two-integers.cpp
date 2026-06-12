class Solution {
    using ll=long long;
public:
    int divide(int dividend, int divisor) {
        long long a = abs((long long)dividend);
long long b = abs((long long)divisor);
if (dividend == INT_MIN && divisor == -1)
    return INT_MAX;
        vector<ll>arr;
        ll c=b;
        ll i=1;
        if (a < b) return 0;
        while(i<=32){
            arr.push_back(c*i);
            i=i*2;
        }
        ll cnt=0;
        while(a!=0){
         ll indx=upper_bound(arr.begin(),arr.end(),a)-arr.begin();
         if(indx==0){
            break;
         }
         a -= c * (1LL << (indx - 1));
         cnt += (1LL << (indx - 1));

        }
        if(dividend<0)cnt=cnt*-1;
        if(divisor<0)cnt=cnt*-1;
        return cnt;
    }
};