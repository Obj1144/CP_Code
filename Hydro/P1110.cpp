#include<bits/stdc++.h>
using namespace std;
using ll=long long;

ll n,l,r;

pair<ll,ll> cal(ll x)
{
    pair<ll,ll> res;
    if(x>n*n){
        
    }
    else{
        for(int i=1;;i++){
            if(i*i>=x){
                res.first=i;
                x-=(i-1)*(i-1);
                ll mid=i*i/2+1;
                if(x<mid) res.second=-abs(x-mid);
                else res.second=abs(x-mid);
                break;
            }
        }
    }
}

void solve()
{
    cin>>n>>l>>r;
    pair<ll,ll> a,b;
    a=cal(l);
    b=cal(r);
    ll ans=abs(a.first-b.first)+abs(a.second-b.second);
    cout<<ans<<"\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int tt;
    cin>>tt;
    while(tt--)
    solve();
}