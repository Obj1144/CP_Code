#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll s[200005];
vector<ll> primes;
const int mod=998244353;
bool isnp[100005];
void euler()
{
    for(int i=2;i<=1e5;i++){
        if(!isnp[i]) primes.push_back(i);
        for(int p:primes){
            if(p*i>1e5) break;
            isnp[i*p]=true;
            if(i%p==0) break;
        }
    }
}
ll foo(ll n,ll lim){
    if(n==1) return lim;
    vector<int> factors;
    for(int p:primes){
        if(n<=1) break;
        if(n%p==0) factors.push_back(p);
        while(n%p==0) n/=p;
    }
    if(n>1) factors.push_back(n);
    ll res=0;
    if(factors.size()==1){
        res=lim-lim/factors[0];
    }
    else{
        for(int i=1;i<(1<<factors.size());i++){
            ll tmp=lim,cot=0;
            for(int j=0;j<factors.size();j++){
                if((i>>j)&1) tmp/=factors[j],cot++;
            }
            if(cot&1) res+=tmp;
            else res-=tmp;
        }
        res=lim-res;
    }
    return res;
}
void solve()
{
    ll n,lim;
    cin>>n>>lim;
    for(int i=1;i<=n;i++) cin>>s[i];
    ll ans=1;
    for(int i=2;i<=n;i++){
        if(s[i-1]%s[i]!=0){
            cout<<"0\n";
            return;
        }
        ll res=foo(s[i-1]/s[i],lim/s[i]);
        ans=(ans*res)%mod;
    }
    cout<<ans<<"\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    euler();
    int tt;
    cin>>tt;
    while(tt--){
        solve();
    }
    return 0;
}