#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int tt;
    cin>>tt;
    while(tt--){
        ll n;
        cin>>n;
        if(n&1) cout<<"3\n";
        else cout<<"2\n";
    }
    return 0;
}