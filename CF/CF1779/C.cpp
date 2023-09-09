#include<bits/stdc++.h>
using namespace std;
using ll=long long;
void solve()
{
    int n,m;
    cin>>n>>m;
    vector<ll> s(n+1,0);
    for(int i=1;i<=n;i++) cin>>s[i];
    if(n==1){
        cout<<"0\n";
        return;
    }
    ll val=0,ans=0;
    // if(s[m]>0) ans++,s[m]=-s[m];
    priority_queue<ll> p;
    for(int i=m;i>1;i--){   
        val+=s[i];
        p.push(s[i]);
        if(val>0){
            ans++;
            ll x=p.top();
            val-=2*x;
            p.pop();
        }
    }
    val=0;
    priority_queue<ll,vector<ll>,greater<ll>> q;
    for(int i=m+1;i<=n;i++){
        val+=s[i];
        if(s[i]<0) q.push(s[i]);
        while(val<0){
            ll x=q.top();
            val-=2*x;
            ans++;
            q.pop();
        }
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
}