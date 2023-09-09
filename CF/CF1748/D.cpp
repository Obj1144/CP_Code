#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll lowbit(ll x){
    return x&-x;
}
void solve()
{
    ll a,b,d;
    cin>>a>>b>>d;
    if(lowbit(d)>lowbit(a)||lowbit(d)>lowbit(b)){
        cout<<"-1\n";
        return;
    }
    ll k=__lg(lowbit(d));
    ll ans=0;
    for(int i=0;i<30;i++){
        if(a&(1<<i)||b&(1<<i)){
            if(ans&(1<<i)) continue;
            ans+=d*(1ll<<(i-k));
        }
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