#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=998244353;
vector<ll> primes;
bool isnp[300005];
ll s[300005];
ll qpow(ll x,ll n){
    ll res=1;
    while(n){
        if(n&1) res=(res*x)%mod;
        x=(x*x)%mod;
        n>>=1;
    }
    return res;
}
void euler()
{
    for(int i=2;i<=1000;i++){
        if(!isnp[i]) primes.push_back(i);
        for(int p:primes){
            if(p*i>1000) break;
            isnp[i*p]=true;
            if(i%p==0) break;
        }
    }
}
void init()
{
    euler();
    int j=1;
    ll res=1;
    for(ll p:primes){
        while(j<p) s[j]=res,j++;
        res*=p;
        if(res>1e12){
            break;
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    init();
    ll n,m;
    cin>>n>>m;
    ll mm=m;
    m%=mod;
    ll ans=0,k=m;
    for(ll i=2;i<=n;i++){
        if(i<37&&s[i]<=mm){
            ll p=mm/s[i];
            p%=mod;
            k=(k*p)%mod;
        }
        else k=0;
        ll res=qpow(m,i);
        res=(res-k+mod)%mod;
        ans+=res;
        ans%=mod;
    }
    cout<<ans<<"\n";
    return 0;
}