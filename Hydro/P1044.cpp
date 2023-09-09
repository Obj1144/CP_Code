#include<bits/stdc++.h>
using std::cin;
using std::cout;
struct node{
    int to;
    int next;
}e[100005];
int s[50001];
std::pair<int,int> ans={0,0};
int n,m,cnt=0,head[50005];
void add(int u,int v){
    e[++cnt].to=v;
    e[cnt].next=head[u];
    head[u]=cnt;
}
void dfs(int x,int fa,int dep,int dp)
{
    dp+=s[x];
    if(dep>ans.first&&dp<=m) ans.first=dep,ans.second=dp;
    if(dep==ans.first) ans.second=std::min(ans.second,dp);
    for(int i=head[x];i;i=e[i].next){
        int to=e[i].to;
        if(to==fa) continue;
        dfs(to,x,dep+1,dp);
    }
}
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>s[i];
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        add(u,v);
        add(v,u);
    }
    dfs(1,0,1,0);
    cout<<ans.first<<" "<<ans.second<<"\n";
}
int main()
{
    std::ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}