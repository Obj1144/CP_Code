#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int a[3005],s[3005],dp[3005];

void solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int x,y;
        cin>>x>>y;
        a[i]=y;
        s[i]=y-x;
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        for(int j=m;j>=a[i];j--){
            dp[j]=max(dp[j],dp[j-a[i]]+s[i]);
            ans=max(ans,dp[j]);
        }
    cout<<ans<<"\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}