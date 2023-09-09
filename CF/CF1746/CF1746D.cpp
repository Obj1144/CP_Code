#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,kk,s[200005];
vector<int> g[200005];
pair<ll,ll> dfs(ll x,ll k)
{
    if(g[x].size()==0) return {k*s[x],s[x]};
    vector<ll> a;
    ll sum=k*s[x];
    int m=g[x].size();
    int y=k/m;
    for(int i:g[x]){
        pair<ll,ll> tmp;
        tmp=dfs(i,y);
        sum+=tmp.first;
        a.push_back(tmp.second);
    }
    sort(a.begin(),a.end());
    if(k%m==0){
        return {sum,a[m-1]+s[x]};
    }
    else{
        int len=k%m;
        reverse(a.begin(),a.end());
        for(int i=0;i<len;i++){
            sum+=a[i];
        }
        return {sum,a[len]+s[x]};
    }
}
void solve()
{
    cin>>n>>kk;
    for(int i=1;i<=n;i++) g[i].clear();
    for(int i=2;i<=n;i++){
        int x;
        cin>>x;
        g[x].push_back(i);
    }
    for(int i=1;i<=n;i++) cin>>s[i];
    pair<ll,ll> ans=dfs(1,kk);
    cout<<ans.first<<"\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int tt;
    cin>>tt;
    while(tt--)
    {
        solve();
    }
    return 0;
}