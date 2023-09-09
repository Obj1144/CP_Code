//unsolved
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
struct line  
{
    int l,r,c,idx;
}s[200005];
int ans[200005];
bool cmp(line a,line b){
    if(a.l==b.l) return a.r>b.r;
    return a.l<b.l;
}
bool cmp2(line a,line b){
    if(a.r==b.r) return a.l>b.l;
    return a.r<b.r;
}
int cal(int r,int l){
    if(r>=l) return 0;
    else return l-r;
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>s[i].l>>s[i].r>>s[i].c,s[i].idx=i,ans[i]=1e9+7;
    sort(s+1,s+n+1,cmp);
    queue<int> pre;
    int lst1,lst2;
    lst1=lst2=0;
    pre.push(1);
    lst1=1;
    for(int i=2;i<=n;i++){
        while(pre.size()&&s[pre.front()].c!=s[i].c){
            int x=pre.front();
            pre.pop();
            ans[s[x].idx]=min(ans[s[x].idx],cal(s[x].r,s[i].l));
        }
        if(s[i].c!=s[lst1].c){
            ans[s[i].idx]=cal(s[lst1].r,s[i].l);
        }
        else if(lst2){
            ans[s[i].idx]=cal(s[lst2].r,s[i].l);
        }
        else pre.push(i);
        if(s[i].r>=s[lst1].r){
            if(s[i].c!=s[lst1].c) lst2=lst1;
            lst1=i;
        }
        else if(s[i].c!=s[lst2].c&&s[i].r>=s[lst2].r){
            lst2=i;
        }
    }
    //-------------------------
    lst1=lst2=0;
    //sort(s+1,s+n+1,cmp2);
    pre.push(n);
    lst1=n;
    for(int i=n-1;i>=1;i--){
        while(pre.size()&&s[pre.front()].c!=s[i].c){
            int x=pre.front();
            pre.pop();
            ans[s[x].idx]=min(ans[s[x].idx],cal(s[i].r,s[x].l));
        }
        if(s[i].c!=s[lst1].c){
            ans[s[i].idx]=min(ans[s[i].idx],cal(s[i].r,s[lst1].l));
        }
        else if(lst2){
            ans[s[i].idx]=min(ans[s[i].idx],cal(s[i].r,s[lst2].l));
        }
        else pre.push(i);
        if(s[i].l<=s[lst1].l){
            if(s[i].c!=s[lst1].c) lst2=lst1;
            lst1=i;
        }
        else if(s[i].c!=s[lst2].c&&s[i].l<=s[lst2].l){
            lst2=i;
        }
    }
    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
    cout<<"\n";
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