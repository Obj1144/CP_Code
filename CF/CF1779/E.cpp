#include<bits/stdc++.h>
using namespace std;
using ll=long long;
void solve()
{
    int n;
    cin>>n;
    vector<pair<int,int>> s(n+1);
    for(int i=1;i<=n;i++){
        cout<<"? "<<i<<" ";
        for(int j=1;j<=n;j++){
            if(j==i) cout<<0;
            else cout<<1;
        }
        cout<<"\n";
        cout.flush();
        cin>>s[i].first;
        s[i].second=i;
    }
    vector<int> ans(n+1,0);
    sort(s.begin()+1,s.end());
    ll sum=0;
    for(int i=n;i>=1;i--){
        sum+=s[i].first;
        ans[s[i].second]=1;
        if((sum-(n-i)*(n-i+1)/2)==((n-i+1)*(i-1))) break;
    }
    cout<<"! ";
    for(int i=1;i<=n;i++) cout<<ans[i];
    cout<<"\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}