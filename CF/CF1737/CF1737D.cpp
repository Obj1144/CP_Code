#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
    int u;
    int v;
    int val;
}e[250005];
int cnt,dis[505][505];
void add(int u,int v,int val){
    e[++cnt].v=v;
    e[cnt].u=u;
    e[cnt].val=val;
}
void solve()
{
    int n,m;
    cin>>n>>m;
    cnt=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            if(i==j) dis[i][j]=0;
            else dis[i][j]=1e9+7;
        }
    for(int i=1;i<=m;i++){
        int u,v,val;
        cin>>u>>v>>val;
        add(u,v,val);  
        dis[u][v]=dis[v][u]=1;
    }
    for(int k=1;k<=n;k++)
         for(int i=1;i<=n;i++)
               for(int j=1;j<=n;j++){
                  dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
             }    
    ll ans=1e18;
    for(int i=1;i<=m;i++){
        ll u=e[i].u,v=e[i].v,w=e[i].val;
        ans=min(ans,(dis[1][u]+dis[v][n]+1)*w);
        ans=min(ans,(dis[1][v]+dis[u][n]+1)*w);
        for(int x=1;x<=n;x++){
            ans=min(ans,(dis[1][x]+dis[x][n]+2+min(dis[u][x],dis[v][x]))*w);
        }
    }
    cout<<ans<<"\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int tt;
    cin>>tt;
    while(tt--){
        solve();
    }
    return 0;
}