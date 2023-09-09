#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll s[100005];
const ll mod=1e9+7;
ll qpow(ll x,ll n){
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
    ll n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    bool p=false;
    for(int l=1,r=n;l<=r;r--,l++){
        if(s[l]>s[r]){
            break;
        }
        else if(s[l]<s[r]){
            p=true;
            break;
        }
    }
    if(p){
        for(int l=1,r=n;l<r;r--,l++){
            swap(s[l],s[r]);
        }
    }
    ll ans=0,k;
    if(p) k=n*(qpow(2,m+1)-1+mod)%mod;
    
    for(int i=1;i<=n;i++){
        ll res=0;
        res=((k-i*m)%mod+mod)%mod;
        res=(res*s[i])%mod;
        ans+=res;
    }
    cout<<ans<<"\n";
    return 0;
}