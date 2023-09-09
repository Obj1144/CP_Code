#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int dp[27];

void solve()
{
    string s;
    cin>>s;
    int k;
    cin>>k;
    int ans=0;
    for(int i=0;i<s.length();i++){
        int x=s[i]-'a';
        int res=0;
        for(int j=0;j<=25;j++){
            if(abs(j-x)>k) continue;
            res=max(res,dp[j]+1);
            ans=max(ans,res);
        }
        dp[x]=max(res,dp[x]);
    }
    cout<<ans<<"\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}