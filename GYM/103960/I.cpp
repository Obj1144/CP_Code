#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    bool ans=true;
    for(int i=1;i<=8;i++){
        int x;
        cin>>x;
        if(x!=0&&x!=1) ans=false;
    }
    if(ans) cout<<"S\n";
    else cout<<"F\n";
    return 0;
}