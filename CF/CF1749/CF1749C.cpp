#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    int n;
    cin>>n;
    vector<int> s(n);
    for(int i=1;i<=n;i++){
        cin>>s[i-1];
    }
    sort(s.begin(),s.end());
    int cot=0,j=0;
    while(s[j]==1) j++,cot++;
    if(cot==0){
        cout<<"0\n";
        return;
    }
    if(cot==n){
        int ans=n/2;
        if(n&1) ans++;
        cout<<ans<<"\n";
        return;
    }
    int ans=(cot/2)+(cot%2);
    for(int i=1;i<=n;i++){
        if(j<n&&s[j]<=i) j++;
        else if(cot>0) cot--;
        else break;
        ans=max(ans,i);
        cot--;
        if(cot<0) break;
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