#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll s[200005];
pair<ll,ll> t[200005];
int tag[200005];
void solve()
{
    int n;
    cin>>n;
    int m=n/3;
    for(int i=1;i<=n;i++) cin>>s[i];
    ll ans=0;
    sort(s+1,s+n+1);
    for(int i=1;i<=n-2;i++)
            ans =max(ans,s[i+1]-s[i]+s[n]-s[i]);
    for(int i=n;i>=3;i--)
            ans =max(ans,s[i]-s[i-1]+s[i]-s[1]);
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