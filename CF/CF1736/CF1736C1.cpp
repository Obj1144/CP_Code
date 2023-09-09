#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int s[200005];
void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>s[i];
    int l=1;
    ll ans=n;
    for(int r=1;r<=n;r++){
        while((r-l+1)>s[r]){
           l++;
        }
        ans+=(r-l);
    }
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