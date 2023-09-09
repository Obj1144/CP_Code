#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[200005],nxt[200005];
void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    s="?"+s;
    for(int i=1;i<=n;i++) cin>>a[i];
    ll ans=0;
    for(int i=1;i<=n;i++){
        if(s[i]=='1') ans+=a[i];
        else if(s[i+1]=='1'){
            int k=i;
            for(i=i+1;i<=n&&s[i]!='0';i++){
                if(a[k]>=a[i]){
                    ans+=a[k];
                    s[i]='0';
                    break;
                }
                ans+=a[i];
            }
            i--;
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