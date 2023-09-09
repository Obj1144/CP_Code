#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    ll n;
    cin>>n;
    vector<int> s;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        s.push_back(x);
    }
    sort(s.begin(),s.end());
    if(s[0]==s[n-1]){
        cout<<n/2<<"\n";
        return;
    }
    ll ans=0;
    for(ll i=0;i<n-1;i++){
        if(s[i]!=s[i+1]){
            ans=max(ans,(i+1)*(n-i-1));
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
    return 0;
}