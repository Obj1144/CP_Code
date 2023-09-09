#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int pre[4000005];
ll k;
ll cal(ll x,ll y)
{
    ll z=x*y^x;
    if(z==0) return x;
    z=__gcd(x,z);
    return z;
}
void foo(ll x)
{
    ll n=(1ll<<k);
    for(int i=1;i<=n;i++){
        ll y=cal(x,i);
        pre[i]=pre[i-1];
        if(y==1) pre[i]++;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll n,x;
    cin>>x>>n;
    k=__lg(x);
    if((1ll<<k)<x) k++;
    ll m=(1ll<<k);
    foo(x);
    while(n--){
        ll l,r;
        cin>>l>>r;
        ll ans=0;
        ans=r/m*pre[m];
        l--;
        ans-=l/m*pre[m];
        l%=m;
        ans-=pre[l];
        r%=m;
        ans+=pre[r];
        cout<<ans<<"\n";
    }
    return 0;
}