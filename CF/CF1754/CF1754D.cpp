#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int s[500005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll n,x;
    cin>>n>>x;
    for(int i=1;i<=n;i++){
        ll y;
        cin>>y;
        s[y]++;
    }
    bool p=true;
    for(int i=1;i<x;i++){
        if(s[i]<=0) continue;
        if(s[i]%(i+1)!=0){
            p=false;
            break;
        }
        else s[i+1]+=s[i]/(i+1);
    }
    if(p) cout<<"Yes\n";
    else cout<<"No\n";
    return 0;
}