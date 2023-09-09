#include<bits/stdc++.h>
using namespace std;
using ll=long long ;
int t[100005];
void solve()
{
    int n,k;
    cin>>n>>k;
    vector<int> s(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    for(int i=1;i<=n;i++){
        t[i]=s[i]-s[i-1];
    }
    vector<ll> cnt(10,0);
    for(int i=0;i<=9;i++)
        for(int j=1;j<=k;j++){
            cnt[i]+=abs(s[j]-i);
        }
    ll ans=1e9;
    for(int l=1,r=k;r<=n;l++,r++){
        if(l!=1){
            for(int i=0;i<=9;i++){
                cnt[i]-=abs(i-s[l-1]);
                cnt[i]+=abs(s[r]-i);
            }
        }
        for(int i=0;i<=9;i++)
            ans=min(ans,cnt[i]);
    }
    cout<<ans<<"\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}