#include<bits/stdc++.h>
using namespace std;
using ll=long long ;
void solve()
{
    ll a,b,c;
    cin>>a>>b>>c;
    if(a<b) swap(a,b);//let a big
    c-=min(c,a-b);
    b+=min(c,a-b);
    cout<<(b+(c/2))/2<<"\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // int tt;
    // cin>>tt;
    // while(tt--){
    solve();
    // }
}