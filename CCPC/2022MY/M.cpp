#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//P R S bu shi jian
bool check(char a,char b){
    if(a==b) return true;
    bool p=true;
    if(a>b) swap(a,b),p=false;
    if(a=='P'&&b=='S') p=(!p);
    return p;
}
struct node{
    int l;
    int r;
    char c;
}a[1000005];
void solve()
{
    string s;
    cin>>s;
    int n=s.length();
    s="?"+s;
    for(int i=1;i<=n;i++) a[i].c=s[i],a[i].l=i-1,a[i].r=i+1;
    
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