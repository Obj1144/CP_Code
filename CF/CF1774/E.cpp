#include<bits/stdc++.h>
using namespace std;
using ll=long long;
map<int,bool> s1,s2;
vector<int> e[200005];
int dis[200005];
int n,d;
ll ans=0;
void dfs1(int x,int fa,map<int,bool>& s1,map<int,bool>& s2)
{
    dis[x]=1e8;
    for(int& i:e[x]){
        if(i==fa) continue;
        dfs1(i,x,s1,s2);
        dis[x]=min(dis[x],dis[i]-1);
    }
    if(dis[x]==0) s1[x]=true;
    if(s2.find(x)!=s2.end()) dis[x]=min(d,dis[x]);
}
bool dfs2(int x,int fa,map<int,bool>& s1)
{
    bool p=false; 
    for(int& i:e[x])
    {
        if(i==fa) continue;
        p|=dfs2(i,x,s1);
    }
    if(s1.find(x)!=s1.end()){
        p=true;
    }
    if(p&&fa){
        ans+=2;
    }
    return p;
}
void solve()
{
    cin>>n>>d;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    int x;
    cin>>x;
    while(x--){int y;cin>>y;s1[y]=true;}
    cin>>x;
    while(x--){int y;cin>>y;s2[y]=true;}
    dfs1(1,0,s1,s2);
    dfs1(1,0,s2,s1);
    // cout<<ans<<"\n";
    // for(auto& i:s1) cout<<i.first<<" ";
    // cout<<"\n";
    // for(auto& i:s2) cout<<i.first<<" ";
    // cout<<"\n";
    dfs2(1,0,s1);
    dfs2(1,0,s2);
    cout<<ans<<"\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}