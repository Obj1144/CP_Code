#include<bits/stdc++.h>
using namespace std;
using ll=long long;

ll cal(string& s)
{
    ll res=0;
    for(auto& i:s){
        int x=i-'a';
        res|=(1<<x);
    }
    return res;
}

void solve()
{
    string a;
    cin>>a;
    map<ll,ll> mp;
    ll ans=0,num=cal(a);
    vector<ll> s;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a;
        ll res=cal(a);
        mp[res]++;
        s.push_back(res);
    }
    for(auto& i:s){
        ll x=i|num;
        if(mp.find(x)!=mp.end()){
            ans+=mp[x];
            if(x==i) ans--;
        }
    }
    cout<<ans<<"\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}
