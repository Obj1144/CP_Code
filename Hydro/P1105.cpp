#include<bits/stdc++.h>
using namespace std;
using ll=long long;

ll n,q;
ll ls(ll x){return x*2;}
ll rs(ll x){return x*2+1;}
ll fa(ll x){return x/2;}
ll num(ll x){
    x=__lg(x);
    return (1ll<<(n-x))-1ll;
}
unordered_map<ll,ll> mp;

void solve()
{
    cin>>n>>q;
    while(q--)
    {
        ll x;
        cin>>x;
        mp[x]=num(x);
        for(x=fa(x);x>=1;x=fa(x)){
            ll y=ls(x);
            if(mp[x]==num(x)) continue;
            mp[x]=0;
            if(mp.find(y)!=mp.end()) mp[x]+=mp[y];
            y=rs(x);
            if(mp.find(y)!=mp.end()) mp[x]+=mp[y];
        }
        cout<<mp[1]<<"\n";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}