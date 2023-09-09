#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll s[100005],ans[100005];
set<int> num,nxt;
void solve()
{
    int n;
    cin>>n;
    num.clear();nxt.clear();
    for(int i=1;i<=n;i++) cin>>s[i],num.insert(i),nxt.insert(i),ans[i]=1;
    for(int i=1;i<=n;i++){
        int x=*num.begin();
        if(s[i]>x){
            int y=*nxt.lower_bound(s[i]-x);
            ans[y]=i+1;
            nxt.erase(y);
        }
        num.erase(s[i]);
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
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