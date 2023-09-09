#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 100005
int s[N],l[N],r[N];
ll cal(ll x)
{
    return (x*x+x)/2;
}
void solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        l[i]=1,r[i]=n;
    }
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        if(a>b) swap(a,b);
        l[b]=max(a+1,l[b]);
    }
    int st=1;
    ll ans=1;
    for(int i=2;i<=n;i++){
        if(l[i]>st) st=l[i];
        ans+=(i-st+1);
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
}
