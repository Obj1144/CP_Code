#include<bits/stdc++.h>
using namespace std;
using ll=long long;

pair<int,int> tag[200005];

void solve()
{
    int n,m;
    cin>>n>>m;
    vector<int> s(n+1);
    vector<vector<int>> e(n+1);
    for(int i=1;i<=n;i++) cin>>s[i],tag[i].first=i,tag[i].second=1;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        
    }
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