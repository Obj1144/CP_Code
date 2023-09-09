#include<bits/stdc++.h>
using namespace std;
using ll=long long;

ll dp[50005][5];

void solve()
{
    int n;
    cin>>n;
    vector<int> s(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        dp[i][0]=max(dp[i][0],dp[i-1][0]);
        dp[i][0]=max(dp[i][0],dp[i-1][1]);

        dp[i][1]=max(dp[i][0],dp[i-1][1]);
        dp[i][1]=max(dp[i][1],dp[i-1][2]);

        dp[i][2]=max(dp[i][1],dp[i-1][2]);
        dp[i][2]=max(dp[i][2],dp[i-1][0]+s[i]);

        ans=max(ans,dp[i][2]);
    }
    cout<<ans<<"\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();    
}