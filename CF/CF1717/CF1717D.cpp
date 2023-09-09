#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=1e9+7;
ll fac[100005];
void init()
{
    fac[0]=fac[1]=1;
    for(int i=2;i<=1e5;i++){
        fac[i]=(fac[i-1]*i)%mod;
    }
}
ll qpow(ll x,ll n){
    ll res=1;
    while(n){
        if(n&1) res=(res*x)%mod;
        x=(x*x)%mod;
        n>>=1;
    }
    return res;
}
ll inv(ll x){
    return qpow(fac[x],mod-2);
}
ll cal(ll n,ll m)
{
    ll res=fac[n]*inv(m);
    res%=mod;
    res*=inv(n-m);
    res%=mod;
    return res;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    init();
    ll n,k;
    cin>>n>>k;
    ll ans=1;
    for(int i=1;i<=min(n,k);i++){
        ans=(ans+cal(n,i))%mod;
    }
    cout<<ans<<"\n";
    return 0;
}