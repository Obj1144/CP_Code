#include<bits/stdc++.h>
using namespace std;
using ll=long long;

vector<int> e[100005];

int dp[100005],dis[100005];

void dfs1(int x,int fa)
{
    for(auto& i:e[x]){
        if(i==fa) continue;
        dfs1(i,x);
        dp[x]=max(dp[x],dp[i]+1);
    }
    dp[x]=max(1,dp[x]);
}

void dfs2(int x,int fa,int dep)
{
    dis[x]=dep;
    int tag=0;
    vector<pair<int,int>> s;
    s.push_back({dep,0});
    for(auto& i:e[x]){
        if(i==fa) continue;
        s.push_back({dp[i],i});
    }
    sort(s.begin(),s.end());
    dis[x]=(*s.rbegin()).first;
    for(auto& i:e[x]){
        if(i==fa) continue;
        auto a=*s.rbegin();
        if(a.second!=i){
            dfs2(i,x,a.first+1);
        }
        else{
            a=s[s.size()-2];
            dfs2(i,x,a.first+1);
        }
    }
}

void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs1(1,0);
    dfs2(1,0,0);
    sort(dis+1,dis+n+1);
    int l=1;
    for(int i=1;i<=n;i++){
        while(l<n&&dis[l]<i) l++;
        if(l<n) cout<<l<<" ";
        else if(l>=n) cout<<n<<" ";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}