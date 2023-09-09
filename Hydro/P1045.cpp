#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n,p,k;
ll mod=1e9+7;
void solve()
{
    int m;
    cin>>m;
    vector<int> step(m+1);
    step[0]=0;
    for(int i=1;i<=m;i++) cin>>step[i],step[i]+=step[i-1];
    auto cal=[&step](int l,int r)->int{return step[r]-step[l];};
    vector<ll> dp(m+1,0);
    dp[0]=1;
    for(int i=1;i<=m;i++){
        for(int j=i-1;j>=0;j--){
            if(i-j>k) break;
            if(cal(j,i)>p) break;
            dp[i]+=dp[j];
            dp[i]%=mod;
        }
    }
    cout<<dp[m]<<"\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>p>>k;
    while(n--){
        solve();
    }
}