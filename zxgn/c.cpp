#include<bits/stdc++.h>
using namespace std;
using ll=long long;

ll a[1005],b[1005],c[1005],dp[1005];

void solve()
{
    int n,m;
    cin>>n>>m;
    ll ans=-1e15;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=1;i<=n;i++) cin>>c[i];
    for(int i=1;i<=n;i++)
        for(int j=m;j>=0;j--){
            if(j>=c[i]) dp[j]=max(dp[j]+a[i],dp[j-c[i]]+b[i]);
            else dp[j]=dp[j]+a[i];
        }
    for(int i=0;i<=m;i++) ans=max(ans,dp[i]);
    cout<<ans+1500<<"\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}