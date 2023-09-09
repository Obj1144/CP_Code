#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll mod=1e9+7;

void solve()
{
    ll n;
    cin>>n;
    ll ans=1,res=1;
    ll m=n/2;
    if(n&1) m++;
    for(ll i=1;i<=n-2;i++){
        ans*=i;
        ans%=mod;
    }
    ans*=(n-1);
    ans%=mod;
    res=m*(m-1);
    res%=mod;
    ans*=res;
    ans%=mod;
    cout<<ans<<"\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}