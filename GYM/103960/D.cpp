#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,ma;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll x,y;
    cin>>n>>x>>y;
    int cot=0;
    while(x%2==0&&y%2==0) cot++,x/=2,y/=2;
    cout<<n-cot-1<<"\n";
    return 0;
}