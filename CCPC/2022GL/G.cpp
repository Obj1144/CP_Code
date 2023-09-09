#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> g[200005];
int val[200005];
struct node{
    multiset<ll> st;
    void add(int x){
        st.insert(x);
    }
    void del(int x){
        st.erase(st.find(x));
    }
    ll operator [] (int id) const{
       // if(id>=st.size()) return 0;
        auto it=st.end();
        for(int i=0;i<=id;i++){
            it--;
        }
        return *it;
    }
}s[200005],l[200005];
ll ans=0;
void dfs(int x,int fa)
{
    for(int i=1;i<=4;i++) l[x].add(0),s[x].add(0);
    for(int i:g[x]){
        if(i==fa) continue;
        dfs(i,x);
        l[x].add(val[i]+l[i][0]);
        s[x].add(s[i][0]);
    }
    s[x].add(val[x]+l[x][0]+l[x][1]);
}
void dfs1(int x,int fa){
    ans=max(ans,l[x][0]+l[x][1]+l[x][2]+l[x][3]);
    for(int i:g[x]){
        if(i==fa) continue;
        s[x].del(val[x]+l[x][0]+l[x][1]);
        s[x].del(s[i][0]);
        l[x].del(val[i]+l[i][0]);
        s[x].add(val[x]+l[x][0]+l[x][1]);
        ans=max(ans,s[x][0]+s[i][0]);
        s[i].del(l[i][0]+val[i]+l[i][1]);
        l[i].add(l[x][0]+val[x]);
        s[i].add(l[i][0]+val[i]+l[i][1]);
        s[i].add(s[x][0]);
        dfs1(i,x);
        s[i].del(s[x][0]);
        s[i].del(l[i][0]+val[i]+l[i][1]);
        l[i].del(l[x][0]+val[x]);
        s[i].add(l[i][0]+val[i]+l[i][1]);
        s[x].del(val[x]+l[x][0]+l[x][1]);
        l[x].add(val[i]+l[i][0]);
        s[x].add(s[i][0]);
        s[x].add(val[x]+l[x][0]+l[x][1]);
    }
}
void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>val[i];
    }
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    dfs1(1,0);
    cout<<ans<<"\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}