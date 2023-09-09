#include<bits/stdc++.h>
using namespace std;
using ll=long long;

void solve()
{
    int n;
    cin>>n;
    if(n<3||n==5){
        cout<<"-1\n";
    }
    else{
        int cnt3,cnt4;
        cnt3=cnt4=0;
        cnt3=n/3-(n%3);
        cnt4=n%3;
        for(int i=1;cnt3>0;cnt3--,i+=2){
            for(int j=1;j<=3;j++) cout<<i<<" 1\n";
        }
        for(int i=1;cnt4>0;cnt4--,i+=3){
            cout<<i<<" 10\n"<<i<<" 11\n";
            cout<<i+1<<" 10\n"<<i+1<<" 11\n";
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}