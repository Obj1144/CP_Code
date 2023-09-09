#include<bits/stdc++.h>
using namespace std;
using ll=long long;
bool solve()
{
    string s,t;
    cin>>s>>t;
    int m,h,y;
    m=h=y=0;
    string ss,tt;
    ss=tt="";
    for(auto& i:s){
        if(i=='m') m++;
        else if(i=='h') h++;
        else if(i=='y') y++;
        else ss+=i;
    }
    for(auto& i:t){
        if(i=='m') m--;
        else if(i=='h') h--;
        else if(i=='y') y--;
        else tt+=i;
    }
    if(m!=h||h!=y) return false;
    if(ss!=tt) return false;
    return true;
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
}