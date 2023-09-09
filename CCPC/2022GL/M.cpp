#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct bittree{
    ll s[300005];
    void init(){
        for(int i=0;i<=3e5;i++) s[i]=0;
    }
    ll lowbit(ll x){
        return x&-x;
    }
    void add(ll x){
        while(x<=3e5){
            s[x]++;
            x+=lowbit(x);
        }
    }
    ll query(ll x){
        ll res=0;
        while(x){
            res+=s[x];
            x-=lowbit(x);
        }
        return res;
    }
}tr;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll n,m;
    cin>>n>>m;
    tr.init();
    bool p=true;
    deque<ll> q;
    ll ans=0;
    for(int i=1;i<=n;i++){
        ll x;
        cin>>x;
        q.push_back(x);
        tr.add(x);
        ans+=i-tr.query(x);
    }
    cout<<ans<<"\n";
    ll MAX=((n-1ll)*n)/2;
    for(int i=1;i<=m;i++){
        char c;
        cin>>c;
        if(c=='S'){
            if(p){
                ll x=q.front();
                q.pop_front();
                q.push_back(x);
                ans+=(n-x);
                ans-=(x-1);
            }
            else{
                ll x=q.back();
                q.pop_back();
                q.push_front(x);
                ans+=(n-x);
                ans-=(x-1);
            }
        }
        else{
            p=!p;
            ans=MAX-ans;
        }
        cout<<ans%10;
    }
    return 0;
}