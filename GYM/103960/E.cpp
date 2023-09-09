#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int mp[1000005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    vector<int> s(n+1);
    for(int i=1;i<=n;i++) cin>>s[i];
    int ans=0;
    for(int i=1;i<=n;i++){
        int x=s[i];
        if(mp[x]==0) ans++,mp[x]=1;
        mp[x]--,mp[x-1]++;
    }
    cout<<ans<<"\n";
    return 0;
}