#include<bits/stdc++.h>
using namespace std;
using ll=long long;

vector<int> e[100005];
int red[100005],blue[100005],green[100005];
int R,G,B;
int ans=0;

void dfs(int x,int fa)
{
    for(auto& i:e[x]){
        if(i==fa) continue;
        dfs(i,x);
        red[x]+=red[i];
        blue[x]+=blue[i];
        green[x]+=green[i];
        int rn,gn,bn;
        rn=R-red[i];
        gn=G-green[i];
        bn=B-blue[i];
        if(rn>0&&bn>0&&gn>0&&blue[i]>0&&green[i]>0&&red[i]>0) ans++;
    }    
}

void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<n;i++){
        int u,v;
        u=i+1;
        cin>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        char c;
        cin>>c;
        if(c=='R') red[i]=1,R++;
        else if(c=='G') green[i]=1,G++;
        else blue[i]=1,B++;
    }
    dfs(1,0);
    cout<<ans<<"\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}