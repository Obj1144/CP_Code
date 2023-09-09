#include <bits/stdc++.h>
using namespace std;
using  ll=long long;

struct node{
    double h,w;
}s[105];

bool cmp(node a,node b){
    if(a.h*a.w==b.h*b.w){
        double x=min(a.h/a.w,a.w/a.h);
        double y=min(b.h/b.w,b.w/b.h);
        if(x==y){
            return a.w<b.w;
        }
        else return x>y;
    }
    return a.h*a.w<b.h*b.w;
}

void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i].w>>s[i].h;
    }
    sort(s+1,s+n+1,cmp);
    for(int i=1;i<=n;i++) cout<<s[i].w<<" "<<s[i].h<<" ";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}