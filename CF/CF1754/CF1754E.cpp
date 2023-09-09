#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=998244353,s[200005];
ll qpow(ll x,ll n)
{
    ll res=1;
    while(n)
    {
        if(n&1) res=(res*x)%mod;
        x=(x*x)%mod;
        n>>=1;
    }
    return res;
}
ll inv(ll x)
{
    return qpow(x,mod-2);
}
//C:\\mingw64\\bin\\g++.exe
void solve()
{
    ll n;
    cin>>n;
    ll cot0=0,cot=0;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        if(s[i]==0) cot0++;
    }
    for(int i=1;i<=cot0;i++){
        if(s[i]==1) cot++;
    }
    ll ans=0;
    ll up=n*(n-1)/2;
    up%=mod;
    for(ll i=1;i<=cot;i++){
        ans+=(inv(i*i)*up)%mod;
        ans%=mod;
    }
    cout<<ans<<"\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int tt;
    cin>>tt;
    while(tt--){
        solve();
    }
    return 0;
}