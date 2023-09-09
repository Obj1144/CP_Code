#include<bits/stdc++.h>
using namespace std;
using ll=long long;
void solve()
{
    int n,x;
    cin>>n>>x;
    vector<vector<ll>> dp(n+1,vector<ll>(x+1,0));
    vector<int> s(n+1),val(n+1);
    for(int i=1;i<=n;i++) cin>>s[i];
    for(int i=1;i<=n;i++) cin>>val[i];
    ll ans=0;
    for(int i=1;i<=n;i++)
        for(int j=x;j>=0;j--){
            dp[i][j]=max(dp[i][j],dp[i-1][j]);
            if(j>=s[i]) dp[i][j]=max(dp[i][j],dp[i-1][j-s[i]]+val[i]);
            if(i>=2&&(j>=(s[i]/2+s[i-1]))) dp[i][j]=max(dp[i][j],dp[i-2][j-s[i]/2-s[i-1]]+val[i]+val[i-1]);
            ans=max(ans,dp[i][j]);
        }
    cout<<ans<<"\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}