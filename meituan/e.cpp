#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int dp[2005][1005][2];

void solve()
{
    int n,k;
    cin>>n>>k;
    vector<int> s(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    int ans=0;
    dp[1][0][1]=s[1];
    for(int i=2;i<=n;i++){
            dp[i][0][0]=max(dp[i-1][0][0],dp[i-1][0][1]);
            dp[i][0][1]=max(dp[i-1][0][1],dp[i-1][0][0]+s[i]);
            ans=max(ans,max(dp[i][0][0],dp[i][0][1]));
        for(int j=1;j<=k;j++){
            dp[i][j][0]=max(dp[i-1][j][0],dp[i-1][j][1]);
            dp[i][j][1]=max(dp[i-1][j-1][1]+s[i],dp[i-1][j-1][0]+s[i]);
            dp[i][j][1]=max(dp[i][j][1],dp[i-1][j][0]);
            ans=max(ans,max(dp[i][j][0],dp[i][j][1]));
        }
    }
    cout<<ans<<"\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();            
}