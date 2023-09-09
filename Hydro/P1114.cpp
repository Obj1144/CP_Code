#include<bits/stdc++.h>
using namespace std;
using ll=long long;

void solve()
{
    int n;
    cin>>n;
    vector<ll> s(n);
    for(int i=0;i<n;i++) cin>>s[i];
    sort(s.begin(),s.end());
    ll ans=1e9;
    for(int i=0;i<n;i++){
        ll r=s[i]+(n-1);
        ll k=upper_bound(s.begin(),s.end(),r)-s.begin();
        k--;
        k=k-i+1;
        ans=min(ans,n-k);
    }
    cout<<ans<<"\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}