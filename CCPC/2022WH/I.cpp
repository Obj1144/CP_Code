#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[50004],num[25],n,k;
bool check(ll mid)
{
    priority_queue<ll> q;
    for(int i=1;i<=n;i++){
        if(mid!=0&&a[i]!=0) q.push(mid*a[i]);
    }
    vector<ll> cot(k+1);
    for(int i=1;i<=k;i++){
        cot[i]=num[i];
    }
    for(int i=k;i>=1;i--){
        while(cot[i]>0){
            if(q.empty()) break;
            ll x=q.top();
            q.pop();
            ll m=(1<<(i-1));
            ll y=min(x/m,cot[i]);
            if(m>=x){
                cot[i]--;
                continue;
            }
            cot[i]-=y;
            x-=y*m;
            if(x!=0) q.push(x);
        }
    }
    if(q.empty()||q.top()==0) return true;
    return false;
}
void solve()
{
    cin>>n>>k;
    ll pre,sum;
    pre=sum=0;
    for(int i=1;i<=n;i++) cin>>a[i],pre+=a[i];
    for(int i=1;i<=k;i++) cin>>num[i],sum+=num[i]*(1<<(i-1));
    ll l=0,r=sum/pre;
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