#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
    int to;
    int next;
    int val;
}e[100005];
ll m,n,c,ans,res,dis[2005][2005],cnt,head[2005];
void add(int u,int v,int val){
    e[++cnt].next=head[u];
    e[cnt].to=v;
    e[cnt].val=val;
    head[u]=cnt;
}
int vis[2005];
void dijkstra(int st)
{
    priority_queue<pair<int,int>> q;
    for(int i=1;i<=2000;i++) vis[i]=0,dis[st][i]=1e15;
    dis[st][st]=0;
    q.push({0,st});
    while(!q.empty()){
        int x=q.top().second;
        q.pop();
        if(vis[x]) continue;
        vis[x]=1;
        for(int i=head[x];i;i=e[i].next){
            int to=e[i].to,val=e[i].val;
            if(dis[st][to]>dis[st][x]+val){
                dis[st][to]=dis[st][x]+val;
                if(!vis[to]) q.push({-dis[st][to],to});
            }
        }        
    }
}
void solve()
{
    cin>>n>>m>>c;
    for(int i=1;i<=m;i++){
        int u,v,val;
        cin>>u>>v>>val;
        add(u,v,val);
    }
    for(int i=1;i<=n;i++) dijkstra(i);
    int ans=0;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++){
            if(dis[i][j]<=c||dis[j][i]<=c) ans=max(ans,1);
            if(dis[i][j]>c||dis[j][i]>c) continue;
            if(dis[i][j]+dis[j][i]<=c){
                ans=2;
            }
        }
    cout<<ans<<"\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}