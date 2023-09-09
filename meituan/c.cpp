#include<bits/stdc++.h>
using namespace std;
using ll=long long;
void solve()
{
    ll n,m;
    cin>>n>>m;
    vector<ll> s(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    sort(s.begin()+1,s.end());
    vector<ll> pre(n+1,0);
    for(int i=1;i<=n;i++){
        pre[i]=s[i]*s[i]+pre[i-1];
    }
    while(m--){
        ll q;
        cin>>q;
        ll k=upper_bound(pre.begin(),pre.end(),q)-pre.begin()-1;
        k=max(0ll,k);
        cout<<k<<" ";
    }
    cout<<"\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();    
}