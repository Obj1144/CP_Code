#include<bits/stdc++.h>
using namespace std;
using ll=long long;

void solve()
{
    ll x;
    vector<ll> s;
    while(cin>>x){
        s.push_back(x);
    }
    ll val=*s.rbegin();
    ll l=0,r=val;
    s.pop_back();

    auto check=[&s,&val](ll x)->bool{
        ll res=0;
        for(int i=0;i<s.size();i++){
            res+=min(x,s[i]);
        }
        return res<=val;
    };

    while(l<=r){
        ll mid=(l+r)/2;
        if(check(mid)) l=mid+1;
        else r=mid;
    }
    cout<<l<<"\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}