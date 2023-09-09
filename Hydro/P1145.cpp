#include<bits/stdc++.h>
using namespace std;
using ll=long long;

ll dp[1005][1005],s[1005][1005];

void solve()
{
    ll n,m,g;
    cin>>n>>m>>g;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            int x;
            cin>>x;
            s[i][j]=x;
        }
    ll ans=1e9;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            dp[i][j]=max(dp[i][j-1],dp[i-1][j])+s[i][j];
            if(dp[i][j]>=g) ans=min(ans,i+j-2ll);
        }    
    if(ans==1e9) cout<<"-1\n";
    else cout<<ans<<"\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}
