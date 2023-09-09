#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[50004],num[25],n,k,worksum,onesum;
bool cmp(ll x,ll y)
{
    return x>y;
}
bool check(ll mid)
{
    vector<ll> s(n);
    for(int i=1;i<=n;i++){
        s[i-1]=mid*a[n-i+1];
    }
    vector<ll> cot(k+1);
    for(int i=1;i<=k;i++) cot[i]=num[i];
    for(int i=k;i>=1;i--){
        for(int j=0;j<s.size();j++){
            if(cot[i]==0) break;
            ll m=(1<<(i-1));
            ll y=s[j]/m;
            if(y<=cot[i]) cot[i]-=y,s[j]%=m;
            else{
                s[j]-=cot[i]*m;
                cot[i]=0;
            }
        }
        if(cot[i]==0) continue;
        ll y=min(cot[i],n);
        nth_element(s.begin(),s.begin()+y-1,s.end(),cmp);
        for(int j=0;j<y;j++){
            s[j]=0;
        }
    }
    if(*max_element(s.begin(),s.end())==0) return true;
    return false;
}
void solve()
{
    cin>>n>>k;
    worksum=onesum=0;
    for(int i=1;i<=n;i++) cin>>a[i],onesum+=a[i];
    for(int i=1;i<=k;i++) cin>>num[i],worksum+=num[i]*(1<<(i-1));
    ll l=0,r=worksum/onesum;//---------------
    while(l<r){
        ll mid=(l+r+1)/2;
        if(check(mid)) l=mid;
        else r=mid-1;
    }
    cout<<l<<"\n";
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