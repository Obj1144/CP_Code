#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int s[25];
void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>s[i];
    if(n==1){
        if(s[1]==1) cout<<"0\n";
        else cout<<"1\n";
        return;
    }
    int res=__gcd(s[1],s[2]);
    for(int i=3;i<=n;i++) res=__gcd(res,s[i]);
    if(res==1) cout<<"0\n";
    else if(__gcd(res,n)==1) cout<<"1\n";
    else if(__gcd(res,n-1)==1) cout<<"2\n";
    else cout<<"3\n";
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