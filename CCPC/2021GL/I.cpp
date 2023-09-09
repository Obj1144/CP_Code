#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    s="?"+s;
    int cot=0;
    ll ans=0;
    for(int i=n;i>=1;i--){
        if(s[i]=='0') cot++;
        else{
            if(cot>0) cot--,ans+=i;
            else cot++;
        }
    }
    cout<<ans<<"\n";
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