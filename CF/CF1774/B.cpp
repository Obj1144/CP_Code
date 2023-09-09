#include<bits/stdc++.h>
using namespace std;
using ll=long long;
void solve()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> s(m+1,0);
    for(int i=1;i<=m;i++){
        cin>>s[i];
    }
    bool p=false;
    int cot=0,lim=(n/k)+((n%k)!=0);
    for(int i=1;i<=m;i++){
        if(s[i]>lim) p=true;
        else if(s[i]==lim) cot++;
    }
    if((n%k!=0)&&(cot>(n%k))) p=true;
    if(p) cout<<"NO\n";
    else cout<<"YES\n";
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