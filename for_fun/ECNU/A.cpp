#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int s[1005][1005];
void solve()
{
    int n,m;
    cin>>n>>m;
    int res=(n%2+n/2)*(m%2+m/2);
    cout<<1<<" "<<res<<"\n";
    int cot=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
            cot++,cout<<cot<<" ";
        cout<<"\n";
    }
    cot=n*m;
    for(int i=1;i<=n;i+=2){
        for(int j=1;j<=m;j+=2){
            s[i][j]=cot;
            cot--;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i][j]) continue;
            s[i][j]=cot;
            cot--;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<s[i][j]<<" ";
        }
        cout<<"\n";
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}