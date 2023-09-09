#include<bits/stdc++.h>
using namespace std;
using ll=long long;
void solve()
{
    int n;
    cin>>n;
    vector<ll> s(n);
    for(int i=0;i<n;i++) cin>>s[i];
    ll ans=0;
    if(n==2) ans=max(s[1]+s[0],abs(s[1]-s[0])*2);
    else if(n==3){
        ans=max(ans,s[0]+s[1]+s[2]+0ll);
        ans=max(ans,s[0]*3+0ll);
        ans=max(ans,s[2]*3+0ll);
        ans=max(ans,s[0]+abs(s[2]-s[1])*2+0ll);
        ans=max(ans,s[2]+abs(s[0]-s[1])*2+0ll);
        ans=max(ans,abs(s[0]-s[1])*3+0ll);
        ans=max(ans,abs(s[2]-s[1])*3+0ll);
    }
    else{
        auto it=max_element(s.begin(),s.end());
        ans=(*it)*n;
    }
    cout<<ans<<"\n";
}
int main()
{
    int tt;
    cin>>tt;
    while(tt--){
        solve();
    }
}