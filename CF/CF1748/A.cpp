#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    ll x;
    cin>>x;
    ll y=x/2;
    ll res=y*y+y;
    if(x&1) res+=y+1;
    if(res>=(y+1)*(y+1)) cout<<y+1<<"\n";
    else cout<<y<<"\n";
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