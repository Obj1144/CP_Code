#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
ll qpow(ll x,ll n)
{
    ll res=1;
    while(n){
        if(n&1) res=(res*x)%mod;
        x=(x*x)%mod;
        n>>=1;
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int tt;
    cin>>tt;
    while(tt--){
        int n;
        cin>>n;
        if(n==1) cout<<"1\n";
        else if(n==2) cout<<"2\n";
        else if(n==3) cout<<"6\n";
        else{
            ll res=qpow(2,n-3);
            res=(6*res)%mod;
            cout<<res<<"\n";
        }
    }
    return 0;
}