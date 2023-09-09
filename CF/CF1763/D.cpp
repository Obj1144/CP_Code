#include<bits/stdc++.h>
using namespace std;
using ll=long long;
//应该是组合数嗯算，不想写了
ll mod=1e9+7;
ll fac[105],inv[105];
ll qpow(ll x,ll n){
    ll res=1;
    while(n){
        if(n&1) res=(res*x)%mod;
        x=(x*x)%mod;
        n>>=1;
    }
    return res;
}
void init()
{
    fac[0]=fac[1]=1;
    inv[0]=qpow(fac[0],mod-2);
    inv[1]=qpow(fac[1],mod-2);
    for(int i=2;i<=100;i++){
        fac[i]=fac[i-1]*i%mod;
        inv[i]=qpow(fac[i],mod-2);
    }    
}
ll cal(ll n,ll m)
{
    ll res=fac[n]*inv[m]%mod;
    res=res*inv[n-m]%mod;
    return res;
}
void solve()
{
    int n,l,r,x,y;
    cin>>n>>l>>r>>x>>y;
    ll ans=0;
    if(x<y){
        for(int i=2;i<=l;i++){

        }
    }

}
int main()
{
    init();
    int tt;
    cin>>tt;
    while(tt--){
        solve();
    }
}