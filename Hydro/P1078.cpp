#include<bits/stdc++.h>
using namespace std;
using ll=long long;
void solve()
{
    int n;
    cin>>n;
    vector<int> l(n+1),r(n+1);
    vector<int> s;
    map<int,bool> mp;
    for(int i=1;i<=n;i++){
        cin>>l[i];
        if(mp[l[i]]) continue;
        s.push_back(l[i]);
        mp[l[i]]=1;
    }
    for(int i=1;i<=n;i++){
        cin>>r[i];
        if(mp[r[i]]) continue;
        s.push_back(r[i]);
        mp[r[i]]=1;
    }
    int cnt=0;
    sort(s.begin(),s.end());
    for(auto& i:s){
        mp[i]=++cnt;
    }
    vector<int> pre(cnt+2,0);
    for(int i=1;i<=n;i++){
        pre[mp[l[i]]]++,pre[mp[r[i]]]--;
    }
    int mx=0;
    for(int i=1;i<=cnt;i++){
        pre[i]=pre[i-1]+pre[i];
        mx=max(mx,pre[i]);
    }
    ll ans=0;
    for(int i=1;i<=cnt;i++){
        if(pre[i]==mx) ans+=s[i+1]-s[i]+1; 
    }
    cout<<mx<<" "<<ans<<"\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}