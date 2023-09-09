#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int n,k,s;
    cin>>n>>k>>s;
    vector<int> cot(n+1,0);
    for(int i=1;i<=s;i++){
        int nn,kk;
        cin>>nn>>kk;
        cot[nn]+=kk;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(cot[i]<k) ans++;
    }
    cout<<ans<<"\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}