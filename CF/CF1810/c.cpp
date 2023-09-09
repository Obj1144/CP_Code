#include<bits/stdc++.h>
using namespace std;
using ll=long long;

void solve()
{
    ll n,c,d;
    cin>>n>>c>>d;
    map<ll,bool> mp;
    ll ans=c*n+d;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        mp[x]=1;
    }
    ll cot=0;
    for(auto& i:mp){
        int x=i.first;
        cot++;
        ll res=(n-cot)*c;
        res+=(x-cot)*d;
        ans=min(res,ans);
    }
    cout<<ans<<"\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int tt;
    cin>>tt;
    while(tt--)
    solve();
}