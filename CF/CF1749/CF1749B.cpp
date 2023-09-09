#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    int n;
    cin>>n;
    ll ans=0;
    for(int i=1;i<=n;i++){
        ll x;
        cin>>x;
        ans+=x;
    }
    ll mx=0;
    for(int i=1;i<=n;i++){
        ll x;
        cin>>x;
        mx=max(mx,x);
        ans+=x;
    }
    ans-=mx;
    cout<<ans<<"\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int tt;
    cin>>tt;
    while(tt--){
        solve();
    }
    return 0;
}