#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll mod=1e9+7;
    ll qpow(ll x,ll n)
    {
        ll res=1;
        while(n){
            if(n&1) res=res*x%mod;
            x=x*x%mod;
            n>>=1;
        }
        return res;
    }
int main()
{
    ll n;
    cin>>n;
    if(n==1) return 0;
    ll res=2;
    n-=2;
    ll ans=qpow(2,n*4)*8;
    cout<<ans<<"\n";
}