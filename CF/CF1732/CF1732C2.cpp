#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll s[100005],xpre[100005],pre[100005],n,q;
int le,ri,L,R;
void init()
{
    pre[0]=0;
    for(int i=1;i<=n;i++) pre[i]=pre[i-1]+s[i];
    xpre[0]=0;
    for(int i=1;i<=n;i++) xpre[i]=xpre[i-1]^s[i];
}
ll cal(ll l,ll r){
    return pre[r]-pre[l-1];
}
ll xcal(ll l,ll r){
    return xpre[r]^xpre[l-1];
}  
bool check(ll len)
{
    for(int i=L;i<=R-len+1;i++){
        if(cal(i,i+len-1)-xcal(i,i+len-1)==cal(L,R)-xcal(L,R)){
            le=i,ri=i+len-1;
            return true;
        }
    }
    return false;
}
void solve()
{
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>s[i];
    init();
    while(q--){
    int l,r;
    cin>>L>>R;
    l=1,r=R-L+1;
    while(l<r){
        int mid=(l+r)/2;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    check(l);
    cout<<le<<" "<<ri<<"\n";
    }
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