#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[5005][3],cd1[5005][3],cd2[5005][3],atk1,atk2,t1,t2,n,s;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>atk1>>t1;
    cin>>atk2>>t2;
    cin>>n>>s;
    ll m=n;
    n+=atk1+atk2;
    for(int i=0;i<=n;i++)
        for(int j=0;j<=2;j++)
            dp[i][j]=-1;
    dp[0][0]=dp[0][1]=dp[0][2]=0;
    cd1[0][0]=cd1[0][1]=cd1[0][2]=t1,cd2[0][0]=cd2[0][1]=cd2[0][2]=t2;// 0=1+2
    for(int i=n;i>=0;i--){
        if(n-i>=atk1){
            
        }
        if(n-i>=atk2){

        }
        if(n-i>=atk1+atk2){

        }
    }
    return 0;
}