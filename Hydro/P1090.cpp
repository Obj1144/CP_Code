#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int n,x,y;
    cin>>n>>x>>y;
    vector<int> s(n+1),t(n+1);
    vector<vector<int>> dp(x+1,vector<int>(y+1,0));//cost count
    for(int i=1;i<=n;i++){
        cin>>s[i]>>t[i];
    }
    pair<int,int> ans={0,0};
    for(int i=1;i<=n;i++){
        for(int j=x;j>=t[i];j--){
            for(int k=y;k>=0;k--){
                if(j>=s[i]) dp[j][k]=max(dp[j-s[i]][k]+1,dp[j][k]);
                if(j>=t[i]&&k>=1) dp[j][k]=max(dp[j-t[i]][k-1]+1,dp[j][k]); 
                if(dp[j][k]>ans.first) ans={dp[j][k],j};
                else if(dp[j][k]==ans.first) ans.second=min(ans.second,j);
            }
        }
    }
    cout<<ans.first<<" "<<ans.second<<"\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}