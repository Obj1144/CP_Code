#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    int n;
    cin>>n;
    int k;
    cin>>k;
    int ans=(k==0);
    for(int i=2;i<=n;i++){
        int x;
        cin>>x;
        k=__gcd(k,x);
        if(i==n) ans+=x/k;
    }
    cout<<ans<<"\n";
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