#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int a[3005],s[3005],dp[3005];

void solve()
{
    int n;
    cin>>n;
    vector<int> s(n+1);
    int l=0,r=0;
    ll val=0;
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    int k;
    cin>>k;
    int cot=0;
    for(int i=1;i<=n;i++) if(s[i]==k) cot++;
    ll ans=1e9;
    vector<int> dp(n+1,0);
    for(int i=1;i<=n;i++){
        dp[i]=dp[i-1]+(s[i]==k);
    }
    for(int l=1,r=cot;r<=n;l++,r++){
        ll res=cot-(dp[r]-dp[l-1]);
        ans=min(res,ans);
    }
    cout<<ans<<"\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}