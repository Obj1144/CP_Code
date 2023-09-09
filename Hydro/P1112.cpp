#include<bits/stdc++.h>
using namespace std;
using ll=long long;

ll ans=0;
ll dp[200005];

void solve()
{
    int n;
    cin>>n;
    vector<pair<int,int>> s(n+1);
    for(int i=1;i<=n;i++) cin>>s[i].first>>s[i].second;
    for(int i=1;i<=n;i++){
        dp[i]=max(dp[i],dp[i-1]);
        ans=max(ans,dp[i]+s[i].first);
        if(i+s[i].second+1<=n) dp[i+s[i].second+1]=max(dp[i+s[i].second+1],s[i].first+dp[i]);
    }
    cout<<ans<<"\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}