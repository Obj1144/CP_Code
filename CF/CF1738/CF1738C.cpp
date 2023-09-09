#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    int n;
    cin>>n;
    int odd,even;
    odd=even=0;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        if(x&1) odd++;
        else even++;
    }
    bool p=false;
    if(odd%4==0) p=true;
    else if(odd%4==1){
        if(even&1) p=true;
    }
    else if(odd%4==3) p=true;
    if(p) cout<<"Alice\n";
    else cout<<"Bob\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int tt;
    cin>>tt;
    while(tt--){
        solve();
    }
    return 0;
}