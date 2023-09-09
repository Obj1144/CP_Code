#include<bits/stdc++.h>
using namespace std;
using ll=long long;
pair<int,int> tr[200005*4];
vector<pair<ll,ll>> s;
vector<ll> L;
map<int,int> mp;
int ls(int x){return x*2;}
int rs(int x){return x*2+1;}
void add(int now,int pos,int l,int r,int val){
    tr[now].first=max(val,tr[now].first);
    tr[now].second=min(val,tr[now].second);
    if(l==r) return;
    int mid=l+(r-l)/2;
    if(pos<=mid)add(ls(now),pos,l,mid,val);
    if(pos>mid)add(rs(now),pos,mid+1,r,val);
}

pair<int,int> query(int now,int ql,int qr,int l,int r)
{
    
}
void solve()
{
    int n,q;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x,y;
        cin>>x>>y;
        s.push_back({x,y});
        L.push_back(x);
    }
    int cnt=0;
    sort(L.begin(),L.end());
    for(auto& i:L){
        if(mp[i]==0) mp[i]=++cnt;
    }
    for(int i=1;i<=n*4;i++){
        tr[i].first=-1e9,tr[i].second=1e9;
    }
    for(auto& i:s){
        add(1,i.first,1,cnt,i.second);
    }
    cin>>q;
    while(q--){
        ll l,r;
        cin>>l>>r;

    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}