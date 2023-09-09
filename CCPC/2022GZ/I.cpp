#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[2005],b[2005],c[2005];
vector<int> g[2005];

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
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
}