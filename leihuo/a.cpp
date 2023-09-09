#include<bits/stdc++.h>
using namespace std;
using ll=long long;

struct node{
    ll x,y,z;
}s[1005],tgt;
ll r;

bool check(node a,node b)
{
    ll res=((a.x-b.x)*(a.x-b.x)
            +(a.y-b.y)*(a.y-b.y)
            +(a.z-b.z)*(a.z-b.z));
    if(r*r>=res) return  true;
    return false; 
}

void solve()
{
    ll n;
    cin>>n>>r;
    for(int i =1;i<=n;i++) cin>>s[i].x>>s[i].y>>s[i].z;
    cin>>tgt.x>>tgt.y>>tgt.z;
    ll ans=0;
    for(int i=1;i<=n;i++){
        if(check(s[i],tgt)) ans++;
    }
    cout<<ans<<"\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}