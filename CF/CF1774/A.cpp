#include<bits/stdc++.h>
using namespace std;
using ll=long long;
void solve()
{
    int n;
    cin>>n;
    int val=0;
    char c;
    cin>>c;
    if(c=='1') val++;
    for(int i=2;i<=n;i++){
        cin>>c;
        if(c=='0') cout<<'+';
        else{
            if(val>0) cout<<'-',val--;
            else cout<<'+',val++;
        }
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