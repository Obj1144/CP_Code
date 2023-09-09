#include<bits/stdc++.h>
using std::cin;
using std::cout;
using ll=long long;
void solve()
{
    int n;
    cin>>n;
    std::vector<ll> s(n+1,0);
    std::vector<ll> dp(100005,0);
    ll res=0;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        res+=s[i];
    }
    if(res&1){
        cout<<0<<"\n";
        return;
    }
    res/=2;
    dp[0]=1;
    for(int i=1;i<=n;i++)
        for(int j=res-s[i];j>=0;j--){
            dp[j+s[i]]+=dp[j];
        }
    cout<<dp[res]<<"\n";
}
int main()
{
    std::ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}