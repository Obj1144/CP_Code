#include<bits/stdc++.h>
using namespace std;
using ll=long long;
void solve()
{
    int n,k;
    cin>>n>>k;
    vector<pair<int,int>> s(n+1,{0,0});
    for(int i=1;i<=n;i++) cin>>s[i].first;
    for(int i=1;i<=n;i++) cin>>s[i].second;
    sort(s.begin()+1,s.end());
    vector<int> suf(n+1,1e5);
    suf[n]=s[n].second;
    for(int i=n-1;i>=1;i--){
        suf[i]=min(suf[i+1],s[i].second);
    }
    int atk=k;
    for(int i=1;i<=n&&k>0;){
        while(i<=n&&s[i].first<=atk) i++;
        if(i>n) break;
        k-=suf[i];
        atk+=k;
    }
    if(atk>=s[n].first) cout<<"YES\n";
    else cout<<"NO\n"; 
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