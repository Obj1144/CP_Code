#include<bits/stdc++.h>
using namespace std;
using ll=long long ;
vector<pair<int,bool>> e[100005];//0黑 1红
int dp[100005][2]={0},ans=0;
void dfs(int x,int fa,int rl,int bl)
{
    int rm=rl,bm=bl;
    for(auto& i:e[x]){
        if(i.first==fa) continue;
        int nrl,nbl;
        nrl=bl,nbl=rl;
        if(i.second)nrl++,nbl=0;
        else nbl++,nrl=0;
        dfs(i.first,x,nrl,nbl);
        if(i.second) rm=max(rm,dp[i.first][0]+1);
        else bm=max(bm,dp[i.first][1]+1);
    }
    ans=max(ans,bm+rm);
    dp[x][0]=max(dp[x][0],bm);
    dp[x][1]=max(dp[x][1],rm);
}
void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        char c;
        cin>>c;
        bool p=(c=='R');
        e[u].push_back({v,p});
        e[v].push_back({u,p});
    }
    dfs(1,0,0,0);
    cout<<ans<<"\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}