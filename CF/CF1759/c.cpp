#include<bits/stdc++.h>
using std::cin;
using std::cout;
using ll=long long;
int solve()
{
    ll l,r,x;
    cin>>l>>r>>x;
    ll a,b;
    cin>>a>>b;
    if(a==b) return 0;
    if(b>r||b<l) return -1;
    ll res=abs(a-b);
    if(res>=x) return 1;
    if(r-std::max(a,b)>=x||std::min(a,b)-l>=x) return 2;
    if((r-b>=x&&a-l>=x)||(r-a>=x&&b-l>=x)) return 3;
    return -1;
}
int main()
{
    std::ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int tt;
    cin>>tt;
    while(tt--){
        cout<<solve()<<"\n";
    }
}