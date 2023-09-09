#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool isnp[100005];
vector<ll> primes;
void euler()
{
    for(int i=2;i<=1e5;i++){
        if(!isnp[i]) primes.push_back(i);
        for(int p:primes){
            if(i*p>1e5) break;
            isnp[i*p]=true;
            if(i%p==0) break;
        }
    }
}
vector<ll> factors;
void initfac(ll x)
{
    for(int p:primes){
        while(x>1&&x%p==0) factors.push_back(p),x/=p;
    }
    if(x>1) factors.push_back(x);
}
void solve()
{
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    map<ll,bool> dp;
    factors.clear();
    initfac(a);
    initfac(b);
    dp[1]=true;
    for(ll i:factors){
        for(auto j:dp){
            ll k=j.first;
            if(i*k<=max(c,d))
            dp[i*k]=true;
        }
    }
    for(auto i:dp){
        ll k=i.first;
        ll x=k*(c/k);
        ll y=(a*b)/k;
        y=(y*(d/y));
        if(x>a&&y>b){
            if(x<=c&&y<=d&&(x*y)%(a*b)==0){
                cout<<x<<" "<<y<<"\n";
                return;
            }
        }
    }
    cout<<"-1 -1\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int tt;
    cin>>tt;
    euler();
    while(tt--){
        solve();
    }
    return 0;
}