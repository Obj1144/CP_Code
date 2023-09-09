#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<int> g[100005];
int dfs(int x,int fa){
    int res=1;
    for(int i:g[x]){
        if(i==fa) continue;
        res=max(res,dfs(i,x)+1);
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ll ans=0;
    for(int i:g[1]){
        ans+=dfs(i,1);
    }
    cout<<ans<<"\n";
    return 0;
}