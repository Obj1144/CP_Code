#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=998244353,s[100005],ans,fac[100005],inv[100005];
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
    for(int i=2;i<=1e5;i++){
        fac[i]=(fac[i-1]*i)%mod;
    }
    inv[100000]=qpow(fac[100000],mod-2);
    for(int i=99999;i>=1;i--){
        inv[i]=(inv[i+1]*(i+1))%mod;
    }
}
ll cal(ll n,ll m){
    if(n==m||m==0) return 1;
    ll res=1;
    res=(fac[n]*inv[m])%mod;
    res=(res*inv[n-m])%mod;
    return res;
}
ll func(ll l,ll r){
    ll i,j;
    i=l,j=r;
    while(i<=r&&(s[i]==0)) i++;
    while(j>=l&&(s[j]==0)) j--;
    if(i==(r+1)) return qpow(2,r-l);
    if(i!=l&&j!=r){
        ll res=0;
        ll x=i-l,y=r-j;
        for(int k=0;k<=min(x,y);k++){
            res=(res+cal(x,k)*cal(y,k))%mod;
        }
        return res*func(i,j)%mod;
    }
    ll pre=s[i],suf=s[j];
    while(pre!=suf){
        if(pre>suf) suf+=s[--j];
        else pre+=s[++i];
    }
    if(i>=j) return 1;
    s[i]=0,s[j]=0;
    return func(i,j);
}
void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>s[i];
    ll ans=func(1,n);
    cout<<ans<<"\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    init();
    int tt;
    cin>>tt;
    while(tt--){
        solve();
    }
    return 0;
}