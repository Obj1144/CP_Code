#include<bits/stdc++.h>
using namespace std;
using ll=long long;

double dp1[21][161],dp2[21][161];

void solve()
{
    int n,m;
    cin>>n>>m;
    vector<double> a(n+1),b(m+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>b[i];
    for(int i=1;i<=a[1];i++) dp1[1][i]=1;
    for(int i=1;i<=b[1];i++) dp2[1][i]=1;

    for(int i=2;i<=n;i++)
        for(int j=1;j<=a[i];j++){
            for(int k=j;k<=160;k++){
                dp1[i][k]+=dp1[i-1][k-j];
            }
        }

    for(int i=2;i<=m;i++)
        for(int j=1;j<=b[i];j++){
            for(int k=j;k<=160;k++){
                dp2[i][k]+=dp2[i-1][k-j];
            }
        }

    double res1,res2;
    res1=res2=1;
    for(int i=1;i<=n;i++) res1*=a[i];
    for(int i=1;i<=m;i++) res2*=b[i];
    for(int i=2;i<=160;i++) dp2[m][i]+=dp2[m][i-1];
    double ans=0;
    for(int i=n;i<=160;i++){
        ans+=(dp1[n][i]/res1)*(dp2[m][i-1]/res2);
    }
    cout << fixed;
    cout.precision(3);
    cout<<ans<<"\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}