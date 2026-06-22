class Solution {
    using ll=long long;
public:
    const int mod=1e9+7;
    ll power(ll base,ll exp){
        ll res=1;
        while(exp>0){
            if(exp%2){
                res=(res*base)%mod;
                exp-=1;
            }
            else{
                base=(base*base)%mod;
                exp=exp/2;
            }
        }
        return res;
    }
    int countGoodNumbers(long long n) {
        ll val=(n+1)/2;
        ll val2=n/2;
        ll num1=power(5,val);
        ll num2=power(4,val2);
        ll ans=(num1*num2)%mod;
        return ans;
    }
};