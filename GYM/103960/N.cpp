#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k;
struct node{
    ll l,r;
    ll sum;
    ll pre;
}tr[10000005];
#define ls(x) (tr[x].l)
#define rs(x) (tr[x].r)
#define sum(x) (tr[x].sum)
#define pre(x) (tr[x].pre)
ll root[200005],s[200005],pre[200005],t[200005];
int cot=0;
void pushup(int x)
{
    sum(x)=sum(ls(x))+sum(rs(x));
    pre(x)=pre(ls(x))+pre(rs(x));
}
void update(int last,int now,int pos,int l,int r)
{
    if(l==r) sum(now)=sum(last)+1,pre(now)=pre(last)+pos;
    else{
        ls(now)=ls(last),rs(now)=rs(last);
        int mid=(l+r-1)/2;
        if(pos<=mid) ls(now)=++cot,update(ls(last),ls(now),pos,l,mid);
        else rs(now)=++cot,update(rs(last),rs(now),pos,mid+1,r);
        pushup(now);
    }
}
ll query(ll last,ll now,ll len,ll l,ll r)
{
    if(l==r){
        return l*len;
    }
    ll rc=sum(rs(now))-sum(rs(last));
    ll mid=(l+r-1)/2;
    if(rc>=len) return query(rs(last),rs(now),len,mid+1,r);
    else return pre(rs(now))-pre(rs(last))+query(ls(last),ls(now),len-rc,l,mid); 
}
const int MAX=1e9+5;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        s[i+n]=s[i];
    }
    for(int i=1;i<=n;i++){
        cin>>t[i];
        t[i+n]=t[i];
    }
    for(int i=1;i<=2*n;i++){
        pre[i]=pre[i-1]+s[i];
        root[i]=++cot;
        update(root[i-1],root[i],t[i],1,MAX);
    }
    cin>>m>>k;
    ll ans=0;
    for(int i=1,j=m;j<=2*n;j++,i++){
        ans=max(ans,pre[j]-pre[i-1]+query(root[i-1],root[j],k,1,MAX));
    }
    cout<<ans<<"\n";
    return 0;
}