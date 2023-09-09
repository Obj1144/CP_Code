#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5;
struct node{
    int sum;
    int l,r;
}tr[N*10];
int cnt=1;
#define ls(x) (tr[x].l)
#define rs(x) (tr[x].r)
#define sum(x) (tr[x].sum)
void pushdown(int x){
    if(!ls(x)) ls(x)=++cnt;
    if(!rs(x)) rs(x)=++cnt;
}
void pushup(int x){
    sum(x)=sum(ls(x))+sum(rs(x));
}
void update(int x,int pos,int l,int r,int k)
{
    if(l==r){
        sum(x)+=k;
        return;
    }
    pushdown(x);
    int mid=(l+r-1)/2;
    if(pos<=mid) update(ls(x),pos,l,mid,k);
    else update(rs(x),pos,mid+1,r,k);
    pushup(x);
}
int query(int x,int l,int r,int L,int R)
{
    if(L>=l&&r<=R) return sum(x);
    if(l>R||r<L) return 0;
    pushdown(x);
    int mid=(l+r-1)/2;
    return query(ls(x),l,mid,L,R)+query(rs(x),mid+1,r,L,R);
}
void add(int x,int k)
{
    update(x,1,1,N,k);
}
void del(int x,int k)
{
    add(x,-1);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

}