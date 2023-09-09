#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll mod=1e9+7;
ll dp[100005];
void solve()
{
    ll n,k;
    cin>>n>>k;
    vector<ll> s(n);
    for(int i=0;i<n;i++) cin>>s[i];
    for(ll& i:s){
        if(i<k) continue;
        
    }
    cout<<dp[k]<<"\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}