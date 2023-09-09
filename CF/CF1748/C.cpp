#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,pre[200005],pos[200005];
ll foo(ll l,ll r){
    map<ll,int> mp;
    for(int i=l;i<=r;i++){
        mp[pre[i]]++;
    }
    ll mx=0;
    for(auto it:mp){
        if(it.second>mp[mx]){
            mx=it.first;
        }
    }
    return mp[mx];
}
void solve()
{
    cin>>n;
    int k=0;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        pre[i]=pre[i-1]+x;
        if(x==0) pos[++k]=i;
    }
    pos[k+1]=n+1;
    ll ans=0;
    for(int i=1;i<pos[1];i++){
        if(pre[i]==0) ans++;
    }
    for(int i=2;i<=k+1;i++){
        ans+=foo(pos[i-1],pos[i]-1);
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