#include<bits/stdc++.h>
using namespace std;
using ll=long long;
vector<int> e[200005];
bool s[200005];
//R 1 B 0
void dfs(int x,int fa)
{
    
}
void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        char c;
        cin>>c;
        if(c=='R') s[i]=true;
    }
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}