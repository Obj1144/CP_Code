#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    int nn;
    cin>>nn;
    int n=nn;
    if(n&1) n--;
    int m=n/2;
    for(int i=m+1,j=1;i<=n;i++,j++) cout<<i<<" "<<j<<" ";
    if(nn&1) cout<<nn;
    cout<<"\n";
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