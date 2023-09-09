#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=998244353,s[100005],ans;
void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>s[i];
    ll pre,suf,cnt;
    int l,r;
    cnt=0;
    pre=s[1],suf=s[n];
    for(l=1,r=n;l<r;r--,suf+=s[r]){
        if(pre==suf) cnt=(cnt*2+1)%mod;
        while(s[l])
        while((pre+s[l+1])<=suf&&(l<(r-1))){
            l++;
            pre+=s[l];
            if(pre==suf) cnt=(cnt*2+1)%mod;
        }
    }
    cnt++;
    cout<<cnt<<"\n";
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