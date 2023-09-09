#include<bits/stdc++.h>
using namespace std;
using ll=long long;
void solve()
{
    ll n;
    cin>>n;
    map<ll,ll> lmp,tmp,rmp,mp;
    ll cnt=0;
    for(ll i=1;i<=n;i++){
        ll p,m;
        char q;
        cin>>p>>q>>m;
        mp[p]=1;
        if(q=='L') lmp[p]=m;
        else if(q=='R') rmp[p]=m;
        else tmp[p]=m;
        cnt+=m;
    }
    ll ans=1e12,res=0;
    bool p=false;
    for(auto& i:mp){
        ll k=i.first;
        ll l,r,t;
        l=r=t=0;
        if(tmp.find(k)!=tmp.end()) t=tmp[k];
        if(lmp.find(k)!=lmp.end()) l=lmp[k];
        if(rmp.find(k)!=rmp.end()) r=rmp[k];
        int cc=0;
        if(l!=0) cc++;
        if(r!=0) cc++;
        if(t!=0) cc++;
        if(cc>=2) p=true;
        else if(t>=2) p=true;
        if(t>=2) t=1ll;
        res+=max(l,max(r,t));
    }
    if(p) cout<<res+1<<"\n";
    else cout<<"-1\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}