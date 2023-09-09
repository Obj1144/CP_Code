#include<bits/stdc++.h>
using std::cin;
using std::cout;
using ll=long long;
const ll mod=1e9+7;
ll fac[100005],inv[100005];
ll qpow(ll x,ll n){
    ll res=1;
    while(n){
        if(n&1) res=(res*x)%mod;
        x=(x*x)%mod;
        n>>=1;
    }
    return res;
}
bool cmp(std::string& a,std::string& b){
    if(a.length()==b.length()) return a<b;
    return a.length()<b.length();
}
void init()
{
    fac[0]=fac[1]=1;
    for(int i=2;i<=1e5;i++){
        fac[i]=fac[i-1]*i%mod;
    }
    inv[100000]=qpow(fac[100000],mod-2);
    for(int i=99999;i>=0;i--){
        inv[i]=(inv[i+1]*(i+1))%mod;
    }
}
void solve()
{
    int n;
    cin>>n;
    std::vector<std::string> s(n);
    for(int i=0;i<n;i++) cin>>s[i];
    sort(s.begin(),s.end(),cmp);
    // for(auto& i:s) cout<<i<<"\n";
    ll ans=1;
    for(int i=0;i<n;){
        int j=i,len=s[i].length();
        while(j<n&&s[j].length()==len) j++;
        ans*=fac[j-i];
        ans%=mod;
        int cot=1;
        i++;
        while(i<j){
            if(s[i]!=s[i-1]) ans*=inv[cot],ans%=mod,cot=1;
            else cot++;
            i++;
        }
        if(cot>1) ans*=inv[cot],ans%=mod;
    }
    cout<<ans<<"\n";
}
int main()
{
    init();
    std::ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}