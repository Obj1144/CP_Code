#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll mod=1e9+7;
ll dp[1000005],mp[1000005];
void solve()
{
    int n;
    cin>>n;
    vector<int> s;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        s.push_back(x);
        mp[x]=1;
    }
    sort(s.begin(),s.end());
    for(auto& i:s){
        for(int j=i*2;j<=1e6;j+=i){
            if(!mp[j]) continue;
            dp[j]++;
            dp[j]+=dp[i];
            dp[j]%=mod;
        }
    }
    ll ans=0;
    for(int i=1;i<=1e6;i++){
        ans+=dp[i];
        ans%=mod;
    }
    cout<<ans<<"\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}