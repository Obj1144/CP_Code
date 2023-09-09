#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> g[2005];
int s[2005],dp[2005][2005],nxt[2005][2005];
void dfs(int u,int fa,int v)
{
    nxt[u][v]=fa;
    for(int& i:g[u]){
        if(i==fa) continue;
        dfs(i,u,v);
    }
}
int cal(int u,int v)
{
    if(u==v) dp[u][v]=1;
    else if(nxt[u][v]==v){
        if(s[u]==s[v]) dp[u][v]=2;
        else dp[u][v]=1;
    }
    if(dp[u][v]>0) return dp[u][v];
    int res=0;
    res=max(cal(nxt[u][v],v),cal(u,nxt[v][u]));
    if(s[u]==s[v])
    res=max(res,cal(nxt[u][v],nxt[v][u])+2);
    return dp[u][v]=res;
}
void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) dp[i][j]=nxt[i][j]=0;
    for(int i=1;i<=n;i++) g[i].clear();
    for(int i=1;i<=n;i++){
        char c;
        cin>>c;
        s[i]=c-'a'+1;
    }
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=1;i<=n;i++) dfs(i,0,i);
    int ans=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        ans=max(ans,cal(i,j));
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
}
