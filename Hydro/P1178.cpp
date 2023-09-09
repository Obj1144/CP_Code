#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int dp[1005];

void solve()
{
    int n,x,c;
    cin>>n>>x>>c;
    vector<int> s(n+1);
    for(int i=1;i<=n;i++) cin>>s[i];
    for(int i=1;i<=n;i++){
        int t;
        cin>>t;
        dp[s[i]]=max(dp[s[i]],t);
    }
    for(int i=1;i<=c;i++)
        for(int j=1;j<=(i/2+1);j++){
            int a=j,b=i-j;
            if(dp[a]==0||dp[b]==0) continue;
            if(a!=b) dp[i]=max(dp[i],dp[a]+dp[b]);
            else dp[i]=max(dp[i],dp[a]*2+x);
        }
    cout<<dp[c]<<"\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}