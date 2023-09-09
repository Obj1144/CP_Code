#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,q,s[300005];
vector<ll> a;
mt19937_64 rnd(114514);
struct bittree{
    ll s[300005];
    ll lowbit(ll x)
    {
        return x&-x;
    }
    ll addint(ll x,ll k){
        while(x<=300000){
            s[x]-=k;
            x+=lowbit(x);
        }
    }
    ll add(ll l,ll r,ll k){
        addint(l,k);
        addint(r+1,-k);
    }
    ll getsum(ll x){
        ll res=0;
        while(x){
            res+=s[x];
            x-=lowbit(x);
        }
        return res;
    }
    ll query(ll l,ll r){
        return getsum(r)-getsum(l-1);
    }
}tr[31];
struct qqq{
    ll i,x,op,l,r,k;
}que[300005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        a.push_back(s[i]);
    }
    for(int i=1;i<=q;i++){
        int op;
        cin>>op;
        que[i].op=op;
        if(op==1){
            cin>>que[i].i>>que[i].x;
            a.push_back(que[i].x);
        }
        else{
            cin>>que[i].l>>que[i].r>>que[i].k;
        }
    }
    sort(a.begin(),a.end());
    
    ll rad[31];
    for(int i=1;i<=30;i++){
        rad[i]=rnd();
    }
    return 0;
}