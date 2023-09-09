#include<bits/stdc++.h>
using namespace std;
using ll=long long ;

ll qpow(ll x,ll n)
{
    ll res=1;
    while(n){
        if(n&1) res*=x;
        x*=x;
        n>>=1;
    }
    return res;
}


bool check(int x)
{
    int num=0;
    ll y=x;
    while(x>0){
        num++;
        x/=10;
    }
    ll res=0;
    x=y;
    while(x>0){
        res+=qpow(x%10,num);
        x/=10;
    }
    if(y==res) return true;
    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i=9;i>=1;i--){
        if(check(i)) cout<<i<<"\n";
    }
}