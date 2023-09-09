#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> primes;
bool isnp[1000006];
ll mod=998244353;
void euler()
{
    for(int i=2;i<=1e6;i++){
        if(!isnp[i]) primes.push_back(i);
        for(ll p:primes){
            if(i*p>1e6) break;
            isnp[i*p]=true;
            if(i%p==0) break;
        }
    }
}
void solve()
{
    euler();
    ll n;
    cin>>n;
    if(n==1){
        cout<<"1\n";
        return;
    }
    vector<ll> fac;
    fac.push_back(1);
    map<ll,int> cot;
    cot[1]=1;
    ll cnt=0;
    for(ll i:primes){
        if(n==1) break;
        if(n%i==0) fac.push_back(i);
        while(n%i==0){
            n/=i;
            cot[i]++;
            cnt++;
        }
    }
    if(n>1) fac.push_back(n),cot[n]++,cnt++;
    ll ans=1;
    for(int i=0;i<fac.size();i++){
        
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}