#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct bittree{
    ll s[500005];
    ll lowbit(ll x){
        return x&-x;
    }
    void add(int x){
        while(x<=5e5){
            s[x]++;
            x+=lowbit(x);
        }
    }
    ll query(int x){
        ll res=0;
        while(x){
            res+=s[x];
            x-=lowbit(x);
        }
        return res;
    }
}tr;
ll ans[500005];
void solve()
{
    ll n,m;
    cin>>n>>m;
    vector<pair<ll,ll>> s;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        s.push_back({x,i});
    }
    sort(s.begin(),s.end());
    ll lst=s[0].first,cot=0;
    ll res=0;
    for(auto i:s){
        ll k=i.first-lst;
        res+=k*cot;
        cot++;
        lst=i.first;
        ans[i.second]=res+tr.query(i.second-1);
        tr.add(i.second);
    }
    for(int i=1;i<=n;i++){
        if(ans[i]>m-2) cout<<"-1\n";
        else cout<<ans[i]<<"\n";
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}