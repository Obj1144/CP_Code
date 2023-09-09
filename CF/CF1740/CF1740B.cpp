#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll s[200005];
void solve()
{
    int n;
    cin>>n;
    ll ans=0;
    for(int i=1;i<=n;i++){
        int x,y;
        cin>>x>>y;
        s[i]=max(x,y);
        ans+=min(x,y)*2;
    }
    sort(s+1,s+n+1);
    s[0]=0;
    for(int i=1;i<=n;i++){
        if(s[i]>s[i-1]) ans+=s[i]-s[i-1];
    }
    ans+=s[n];
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
    return 0;
}