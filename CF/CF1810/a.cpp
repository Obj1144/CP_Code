#include<bits/stdc++.h>
using namespace std;
using ll=long long;

void solve()
{
    int n;
    cin>>n;
    bool p=false;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        if(x<=i) p=true;
    }
    if(p) cout<<"YES\n";
    else cout<<"NO\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int tt;
    cin>>tt;
    while(tt--)
    solve();
}