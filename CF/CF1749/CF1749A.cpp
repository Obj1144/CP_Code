#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    int col[9],row[9];
    for(int i=1;i<=8;i++) col[i]=row[i]=0;
    int n,m;
    cin>>n>>m;
    int cotr=n,cotc=n;
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        row[x]++,col[y]++;
        if(row[x]==1) cotr--;
        if(col[y]==1) cotc--;
    }
    if(cotr>0||cotc>0) cout<<"Yes\n";
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