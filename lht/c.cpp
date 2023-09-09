#include <bits/stdc++.h>
using namespace std;
using  ll=long long;

pair<int,int> s[25];
ll dp[1000005];

void solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=1e6;i++) dp[i]=1e9;
    for(int i=1;i<=n;i++){
        vector<int> status(n,0);
        for(int i=n-1;i>=n-i;i--) status[i]=1;
        while(1){
            ll res=0;
            for(int i=n-1;i>=0;i--){
                if(status[i]) res+=(1<<(n-1-i));
            }
            
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}