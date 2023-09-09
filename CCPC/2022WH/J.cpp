#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    ll n,m;
    cin>>n>>m;
    vector<ll> s,lim,nxt;    
    map<ll,int> mp;
    for(int i=1;i<=n;i++){
        ll x;
        cin>>x;
        s.push_back(x);
    }
    sort(s.begin(),s.end());
    lim.push_back(-1);
    for(int i=1;i<=m;i++){
        ll x,y;
        cin>>x>>y;
        mp[x]=y;
        if(y==0) lim.push_back(x);
    }
    lim.push_back(1e10);
    sort(lim.begin(),lim.end());
    for(ll i:lim) nxt.push_back(i+1);
    ll cnt=0;
    for(ll i:s){
        int it=upper_bound(lim.begin(),lim.end(),i)-lim.begin();
        it--;
        ll x=nxt[it];
        while(1){
            if(mp.find(x)==mp.end()) break;
            if(mp[x]>0) break; 
            x++;
        }
        if(mp.find(x)==mp.end()) cnt+=i-x;
        else if(mp[x]>0) cnt+=i-x,mp[x]--;
        nxt[it]=x;
    }
    if(cnt&1) cout<<"Pico\n";
    else cout<<"FuuFuu\n";
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