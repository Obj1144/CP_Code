#include<bits/stdc++.h>
using namespace std;
using ll=long long;
bool solve()
{
    int n;
    cin>>n;
    vector<int> a(n+1),b(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    stack<int> s;
    for(int i=1,j=1;j<=n;){
        if(i<=n) s.push(a[i]),i++;  
        while(!s.empty()&&j<=n&&s.top()==b[j]) s.pop(),j++;
        if(i>n&&j<=n) return false;
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int tt;
    cin>>tt;
    while(tt--){
        bool p=solve();
        if(p) cout<<"Yes\n";
        else cout<<"No\n";
    }
}