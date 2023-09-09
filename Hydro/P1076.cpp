#include<bits/stdc++.h>
using namespace std;
int dp[105][105][105];
bool tgt[105][3];
int dp2[2][105][105][105];
void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) {
        string s;
        cin>>s;
        for(auto& j:s){
            if(j=='A') tgt[i][0]=true;
            if(j=='B') tgt[i][1]=true;
            if(j=='C') tgt[i][2]=true;
        }
    }

    int lim[4],cost[4];
    for(int i=1;i<=3;i++) cin>>lim[i]>>cost[i];
    
    for(int i=0;i<=n;i++)
        for(int j=0;j<=lim[1];j++)
            for(int k=0;k<=lim[2];k++)
                dp[i][j][k]=1e7+5;
    dp[0][0][0]=0;
    
    int ans=1e7+5;

    for(int i=1;i<=n;i++)
        for(int j=min(lim[1],i);j>=0;j--){
            for(int k=min(lim[2],i-j);k>=0;k--){
                int l=i-j-k;
                if(l>lim[3]) break;
                if(tgt[i][0]&&j>0) dp[i][j][k]=min(dp[i][j][k],dp[i-1][j-1][k]+cost[1]);
                if(tgt[i][1]&&k>0) dp[i][j][k]=min(dp[i][j][k],dp[i-1][j][k-1]+cost[2]);
                if(tgt[i][2]&&l>0) dp[i][j][k]=min(dp[i][j][k],dp[i-1][j][k]+cost[3]);
                if(i==n) ans=min(ans,dp[i][j][k]);
            }
        }
    if(ans<1e7)
    {
        cout<<"YES\n";
        cout<<ans<<"\n"; 
        return;
    } 
    int res=0;
    for(int i=1;i<=n;i++)
        for(int j=min(i,lim[1]);j>=0;j--)
            for(int k=min(i-j,lim[2]);k>=0;k--)
                for(int l=min(i-j-k,lim[3]);l>=0;l--){
                    dp2[i&1][j][k][l]=max(dp2[i&1][j][k][l],dp2[!(i&1)][j][k][l]);
                    if(tgt[i][0]&&j>0) dp2[i&1][j][k][l]=max(dp2[i&1][j][k][l],dp2[!(i&1)][j-1][k][l]+1);
                    if(tgt[i][1]&&k>0) dp2[i&1][j][k][l]=max(dp2[i&1][j][k][l],dp2[!(i&1)][j][k-1][l]+1);
                    if(tgt[i][2]&&l>0) dp2[i&1][j][k][l]=max(dp2[i&1][j][k][l],dp2[!(i&1)][j][k][l-1]+1);
                    res=max(res,dp2[i&1][j][k][l]);
                }
    cout<<"NO\n";
    cout<<res<<"\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}