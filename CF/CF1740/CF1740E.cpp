#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> g[200005];
int son[200005],dep[200005];
void dfs(int x)
{
    int y,z,mx;
    y=z=mx=0;
    for(int i:g[x]){
        dfs(i);
        z=max(dep[i],z);
        y+=son[i];
    }
    dep[x]=z+1;   
    son[x]=max(dep[x],y);
}
void solve()
{
    int n;
    cin>>n;
    for(int i=2;i<=n;i++){
        int x;
        cin>>x;
        g[x].push_back(i);
    }
    dfs(1);
    cout<<max(dep[1],son[1])<<"\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}