#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int col[100005],now[1000005],ans;
vector<int> g[1000005];
void merge(int x,int y)
{
    for(int i:g[x]){
        if(y==col[i-1]) ans--;
        if(y==col[i+1]) ans--;
    }
    for(int i:g[x]){
        col[i]=y;
        g[y].push_back(i);
    }
    g[x].clear();
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>col[i];
        now[col[i]]=col[i];
        g[col[i]].push_back(i);
        if(col[i]!=col[i-1]) ans++;
    }
    for(int i=1;i<=m;i++){
        int op;
        cin>>op;
        if(op==1){
            int x,y;
            cin>>x>>y;
            if(x==y) continue;
            if(g[now[x]].size()>g[now[y]].size()) swap(now[x],now[y]);
            merge(now[x],now[y]);
        }
        else{
            cout<<ans<<'\n';
        }
    }
    return 0;
}