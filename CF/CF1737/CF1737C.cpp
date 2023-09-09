#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
    int x,y;
}s[5];
bool cmp(node a,node b){
    if(a.x==b.x) return a.y<b.y;
    return a.x<b.x;
}
bool solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=3;i++) cin>>s[i].x>>s[i].y;
    int x,y;
    cin>>x>>y;
    sort(s+1,s+4,cmp);
    if((s[1].x==1&&s[1].y==1)&&(s[2].x==1&&s[2].y==2)&&(s[3].x==2&&s[3].y==1)){
        if(x==1||y==1) return true;
        return false;
    }
    else if((s[1].x==(n-1)&&s[1].y==1)&&(s[2].x==n&&s[2].y==1)&&(s[3].x==n&&s[3].y==2)){
        if(x==n||y==1) return true;
        return false;
    }
    else if((s[1].x==1&&s[1].y==n-1)&&(s[2].x==1&&s[3].y==n)&&(s[3].x==2&&s[3].y==n)){
        if(x==1||y==n) return true;
        return false;
    }
    else if((s[1].x==n-1&&s[1].y==n)&&(s[2].x==n&&s[2].y==n-1)&&(s[3].x==n&&s[3].y==n)){
        if(x==n||y==n) return true;
        return false;
    }
    int lx=min(s[1].x,min(s[2].x,s[3].x));
    int ly=min(s[1].y,min(s[2].y,s[3].y));
    if(s[1].x!=lx||s[1].y!=ly){
        int a=abs(lx-x);
        int b=abs(ly-y);
        a%=2,b%=2;
        if(a||b) return true;
        return false;
    }
    else if(s[3].x==lx||s[3].y==ly){
        int a=abs((lx+1)-x);
        int b=abs((ly+1)-y);
        a%=2,b%=2;
        if(a||b) return true;
        return false;
    }
    else if(s[2].x!=lx){
        int a=abs(lx-x);
        int b=abs((ly+1)-y);
        a%=2,b%=2;
        if(a||b) return true;
        return false;        
    }//l-d
    else{
        int a=abs((lx+1)-x);
        int b=abs(ly-y);
        a%=2,b%=2;
        if(a||b) return true;
        return false;          
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int tt;
    cin>>tt;
    while(tt--){
        bool p=solve();
        if(p) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}