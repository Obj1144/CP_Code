#include<bits/stdc++.h>
using namespace std;
using ll=long long;
void move(pair<int,int>& point,char op)
{
    if(op=='U') point.first--;
    else if(op=='D') point.first++;
    else if(op=='L') point.second--;
    else point.second++;
}
ll n,m;
int tree[1005][1005];
void add(int x, int y, int z){ 
    int memo_y = y;
    while(x <= n){
        y = memo_y;
        while(y <= m)
            tree[x][y] += z, y += y & -y;
        x += x & -x;
    }
}
void range_add(int xa, int ya, int xb, int yb, int z){
    add(xa, ya, z);
    add(xa, yb + 1, -z);
    add(xb + 1, ya, -z);
    add(xb + 1, yb + 1, z);
}
ll ask(int x, int y){
    int res = 0, memo_y = y;
    while(x){
        y = memo_y;
        while(y)
            res += tree[x][y], y -= y & -y;
        x -= x & -x;
    }
    return res;
}


void solve()
{
    ll k;
    cin>>n>>m>>k;
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
            tree[i][j]=0;
    string s;
    cin>>s;
    pair<int,int> a,b,l,r;
    a.first=a.second=1;
    b.first=m,b.second=n;
    l=a,r=b;
    for(char& i:s){
        move(a,i);
        move(b,i);
        if(a.first<=0) l.first=max(l.first,l.first+1),a.first=1;
        else if(a.second<=0) l.second=max(l.second,l.second+1),a.second=1;
        if(b.first>n) r.first=min(r.first,r.first-1),b.first=n;
        else if(b.second>m) r.second=min(r.second-1,r.second),b.second=m;
    }
    if(r.first<l.first||r.second<l.second){
        if(k==0) cout<<n*m<<"\n";
        else cout<<"0\n";
        return;
    }
    int res=(r.first-l.first+1)*(r.second-l.second+1)-k;
    range_add(l.first,l.second,r.first,r.second,1);
    map<pair<int,int>,bool> mp;
    mp[l]=true;
    for(char& i:s){
        move(l,i);
        move(r,i);
        if(mp[l]) continue;
        mp[l]=true;
        range_add(l.first,l.second,r.first,r.second,1);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int x=ask(i,j);
            if(x==res) ans++;
        }
    }
    cout<<ans<<"\n";
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