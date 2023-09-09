#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,nxt[1000005];
vector<ll> g[1000005];
int sz[1000005];
void dfs(int x)
{
    sz[x]=1;
    for(int i:g[x]){
        dfs(i);
        sz[x]+=sz[i];
    }
}
string s;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>k;
    cin>>s;
    s="?"+s;
    nxt[0]=-1,nxt[1]=0;
    for(int i=2;i<=n;i++){
        nxt[i]=nxt[i-1];
        while(nxt[i]&&s[nxt[i]+1]!=s[i]) nxt[i]=nxt[nxt[i]];
        if(s[i]==s[nxt[i]+1]) nxt[i]++;
    }
    for(int i=1;i<=n;i++) g[nxt[i]].push_back(i);
    dfs(0);
    int ans=-1;
    for(int i=n;i>=1;i=nxt[i]){
        if(sz[i]>=k) ans=max(ans,i);
    }
    if(ans==-1) cout<<"-1\n";
    else{
        for(int i=1;i<=ans;i++) cout<<s[i];
        cout<<"\n";
    }
    return 0;
}