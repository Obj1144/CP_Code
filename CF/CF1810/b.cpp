#include<bits/stdc++.h>
using namespace std;
using ll=long long;

map<ll,ll> dp;

void solve()
{
    ll x;
    cin>>x;
    if(x%2==0){
        cout<<"-1\n";
    }
    else{
        stack<int> ans;
        while(1){
            ll a=(x-1)/2;
            ll b=(x+1)/2;
            if(a&1){
                ans.push(2);
                x=a;
            }
            else{
                ans.push(1);
                x=b;
            }
            if(x==1) break;
        }
        cout<<ans.size()<<"\n";
        while(!ans.empty()){
            cout<<ans.top()<<" ";
            ans.pop();
        }
        cout<<"\n";
    }
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