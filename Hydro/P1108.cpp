#include<bits/stdc++.h>
using namespace std;
using ll=long long;

bool solve()
{
    int n,k;
    cin>>n>>k;
    string s,t;
    cin>>s>>t;
    for(int i=1;i<=k;i++){
        int mp[27];
        memset(mp,0,sizeof(mp));
        for(int j=i-1;j<n;j+=k){
            mp[s[j]-'a']++;
            mp[t[j]-'a']--;
        }        
        for(int j=0;j<=25;j++){
            if(mp[j]!=0) return false;
        }
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