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
    int cot0=0,cot1=0;
    for(int i=1;i<=n;i++){
        if(s[i]=='0'&&s[i-1]!=s[i]) cot0++;
        else if(s[i]=='1'&&s[i-1]!=s[i]) cot1++;
    }
    if(cot1==0||cot0==0) cout<<"0\n";
    else{
        if(cot0<cot1) cout<<2*(cot0)<<"\n";
        else if(cot0>cot1) cout<<2*cot1-1<<"\n";
        else{
            if(s[1]=='0') cout<<2*(cot0-1)<<"\n";
            else cout<<2*cot1-1<<"\n";
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int tt;
    cin>>tt;
    while(tt--)
    {
        solve();
    }
    return 0;
}