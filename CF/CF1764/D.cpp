#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll fac[5005],pre[5005];
void solve()
{
    ll n,mod;
    cin>>n>>mod;
    fac[0]=fac[1]=1;
    pre[1]=2,pre[0]=1;
    for(int i=2;i<=n;i++){
        fac[i]=(fac[i-1]*i)%mod;
        pre[i]=(pre[i-1]+pre[i])%mod;
    }
    ll k=n/2;
    if(n%2==0) k--;
    ll ans=0;
    for(int i=2;i<=k+1;i++){
        ll l,r;
        l=1+(n/2),r=i+(n/2);
        if(n&1) l++;
        ll res=(fac[i-2]*fac[n-i-1])%mod;
        res=res*(r-l+1)%mod;
        ll aa=(1<<(i-2));
        res=(res*aa)%mod;
        res=(res*n)%mod;
        ans=(ans+res)%mod;
    }
    if(n%2==0){
        ll m=n-2;
        ll res=fac[m];
        res=(res*n)%mod;        
        ans=(ans+res)%mod;
    }
    cout<<ans<<"\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}