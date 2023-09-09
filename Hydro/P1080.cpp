#include<bits/stdc++.h>
using namespace std;
using ll=long long;
void solve()
{
    ll n;
    cin>>n;
    for(ll i=1e5;i>=1;i--){
        ll x=(i*i+i)/2+2;
        while(n>=x){
            n-=x;
            for(int j=1;j<=i;j++) cout<<"r";
            cout<<"ed";
        }
        if(n==0) break;
    }
    while(n>=3) cout<<"red",n-=3;
    if(n==2) cout<<"re";
    else if(n==1) cout<<"r";
    cout<<"\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}