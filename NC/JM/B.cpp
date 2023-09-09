#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll inv[10000005],fac[10000005],mod=1e9+7;
ll dp[305][90005],s[305],pre[90005];
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
void init()
{
    fac[0]=fac[1]=1;
    for(int i=2;i<=1e7;i++){
        fac[i]=(fac[i-1]*i)%mod;
    }
    inv[10000000]=qpow(fac[10000000],mod-2);
    for(int i=1e7-1;i>=1;i--){
        inv[i]=(inv[i+1]*(i+1))%mod;
    }
}
ll cal(ll n,ll m)
{
    if(m==0||n==m) return 1;
    ll res=fac[n]*inv[n-m];
    res%=mod;
    res=(res*inv[m])%mod;
    return res;
}
void solve()
{
    int n,m,k;
    cin>>n>>m>>k;
    ll ma=0;
    for(int i=1;i<=m;i++) cin>>s[i],ma+=s[i];
    dp[0][0]=1;
    for(int i=1;i<=m;i++){
        pre[0]=0;
       for(ll j=0;j<=ma;j++){
        pre[j+1]=pre[j]+dp[i-1][j];
        pre[j+1]%=mod;
       }
       for(ll j=0;j<=ma;j++){
        dp[i][j]=pre[j+1]-pre[max(0ll,j-s[i])]+mod;
        dp[i][j]%=mod;
       }
    }
    ll ans=0;
    if(n==m){
        cout<<dp[n][ma]<<"\n";
        return;
    }
    for(ll i=0;i<=ma;i++){
        ans+=(cal(n-m+k-i-1,n-m-1)*dp[m][i])%mod;
        ans%=mod;
    }
    cout<<ans<<"\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    init();
    solve();
    return 0;
}