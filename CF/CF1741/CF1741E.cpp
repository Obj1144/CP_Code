#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int s[200005],dp[200005];
void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>s[i],dp[i]=false;
    dp[0]=true;
    for(int i=1;i<=n;i++){
        if(dp[i-1]&&(i+s[i]<=n)){
            dp[i+s[i]]=true;
        }
        if((i-s[i]>=1)&&dp[i-s[i]-1]){
            dp[i]=true;
        }
    }
    if(dp[n]) cout<<"Yes\n";
    else cout<<"No\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int tt;
    cin>>tt;
    while(tt--){
        solve();
    }
    return 0;
}