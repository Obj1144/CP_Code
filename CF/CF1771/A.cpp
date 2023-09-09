#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 100005
ll a[N];
void solve()
{
    int n;
    cin>>n;
    memset(a,0,sizeof(a));
    ll mx,mi;
    mx=0,mi=1e9;
    for(int i=1;i<=n;i++){
        ll x;
        cin>>x;
        a[x]++;
        mx=max(mx,x);
        mi=min(mi,x);
    }
    if(mi==mx) cout<<((a[mi]-1)*(a[mi]-1)+a[mi]-1)<<"\n";
    else cout<<a[mi]*a[mx]*2<<"\n";
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
}