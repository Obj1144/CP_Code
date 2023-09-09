#include<bits/stdc++.h>
using namespace std;
using ll=long long;
void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    s="?"+s;
    int cot0=0,cot1=0;
    for(int i=1;i<n;i++){
        if(s[i]=='0'){
            cot1=0;
            cot0++;
        }
        else{
            cot0=0;
            cot1++;
        }
        cout<<i-max(cot0,cot1)+1<<" ";
    }
    cout<<"\n";
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