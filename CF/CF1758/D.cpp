#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    int n;
    cin>>n;
    int x=4*n,y=n;
    for(int i=1;i<n;i+=2){
        cout<<x+y<<" "<<x-y<<" ";
        y--;
    }
    if(n&1) cout<<x;
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