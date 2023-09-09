#include<bits/stdc++.h>
using namespace std;
using ll=long long;

void solve()
{
    ll n,k;
    cin>>n>>k;
    vector<int> s(n+1);
    for(int i=1;i<=n;i++) cin>>s[i];
    ll l=1,ans=0;
    for(int i=1;i<=n;i++){
        if(s[i]<=k) ans+=(i-l),l=l+1;
    }
    cout<<ans<<"\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}