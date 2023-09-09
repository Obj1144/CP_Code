#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int cot=0;
    for(int i=0;i<n;i++){
        if(s[i]=='Q') cot++;
        else cot=max(0,cot-1);
    }
    if(cot>0) cout<<"No\n";
    else cout<<"Yes\n";
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