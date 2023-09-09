#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+7;
struct node{
    int sum;
    int l,r;
}tr[N*100];
int root[N];
#define ls(x) (tr[x].l)
#define rs(x) (tr[x].r)
#define sum(x) (tr[x].sum)
int cnt=1;
void pushup(int x)
{
    sum(x)=sum(ls(x))+sum(rs(x));
}
void update(int last,int now,int pos,int l,int r,int k)
{
    if(l==r){
        sum(now)=sum(last)+k;
    }
    else{
        ls(now)=ls(last),rs(now)=rs(last);
        int mid=(l+r-1)/2;
        if(pos<=mid) ls(now)=++cnt,update(ls(last),ls(now),pos,l,mid,k);
        else rs(now)=++cnt,update(rs(last),rs(now),pos,mid+1,r,k);
        pushup(now);
    }
}
int query(int last,int now,int k,int l,int r)
{
    if(l==r) return l;
    int val=sum(ls(now))-sum(ls(last));
    int mid=(l+r-1)/2;
    if(val>=k) return query(ls(last),ls(now),k,l,mid);
    else return query(rs(last),rs(now),k-val,mid+1,r);
}
const int MAX=1e9;
void solve()
{
    int n,m;
    cin>>n>>m;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        root[i]=++cnt;
        update(root[i-1],root[i],a[i],-MAX,MAX,1);
    }
    while(m--)
    {
        int l,r,k;
        cin>>l>>r>>k;
        int ans=query(root[l-1],root[r],k,-MAX,MAX);
        cout<<ans<<"\n";
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}