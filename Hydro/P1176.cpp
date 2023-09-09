#include<bits/stdc++.h>
using namespace std;
using ll=long long;
vector<pair<int,int>> t[1000005];
unordered_map<int,int> mp;
int cnt=0;
void solve()
{
    int n;
    cin>>n;
    vector<int> s(n+1);
    for(int i=1;i<=n;i++) cin>>s[i],s[i]+=s[i-1];
    for(int i=1;i<=n;i++) 
        for(int l=1,r=i;r<=n;l++,r++){
            ll x=s[r]-s[l-1];
            if(mp.find(x)==mp.end()) mp[x]=++cnt;
            t[mp[x]].push_back({r,l});
        }
    int ans=1;
    for(int i=1;i<=cnt;i++){
        sort(t[i].begin(),t[i].end());
        int res,lst;
        res=lst=0;
        for(auto& j:t[i]){
            if(j.second<=lst) continue;
            lst=j.first;
            res++;
        }
        ans=max(ans,res);
    }
    cout<<ans<<"\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}