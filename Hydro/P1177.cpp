#include<bits/stdc++.h>
using namespace std;
using ll=long long;

vector<int> e[1000005];

int n,dp[1000005];
pair<int,int> ans{1e7,0};

void dfs(int x,int fa)
{
    dp[x]=1;
    for(auto& i:e[x]){
        if(i==fa) continue;
        dfs(i,x);
        dp[x]+=dp[i];
        int a=abs(n-dp[i]*2);
        if(a<ans.first) ans.first=a,ans.second=1;
        else if(a==ans.first) ans.second++;
    }
}

void solve()
{
    cin>>n;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1,0);
    cout<<ans.first<<" "<<ans.second<<"\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}