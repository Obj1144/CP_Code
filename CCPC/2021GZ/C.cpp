#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll s[100005];
bool check(ll mid)
{
    ll k=mid,lst=s[1]-1;
    for(int i=1;i<=m;i++){
        ll r=i;
        r=lst+mid;
        r=min(r,s[i+1]-1);
        k=min(k,r-s[i]);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++) cin>>s[i];
    ll l,r;
    l=1,r=n;
    while(l<r){
        ll mid=(l+r+1)/2;
        if(check(mid)) l=mid;
        else r=mid-1;
    }
    cout<<l<<"\n";
    return 0;
}