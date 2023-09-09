#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int tr[100005];
void solve()
{
    int n;
    cin>>n;
    vector<int> s(n+1);
    for(int i=1;i<=n;i++) cin>>s[i];
    sort(s.begin()+1,s.end());
    vector<int> t(n+1,0),pre(n+1,0);
    int cnt = 0;
    for(int i=1;i<=n;i++){
        if(s[i]!=s[i-1]) t[++cnt]=1;
        else t[cnt]++;
    }
    int ans = 0;
    while(cnt>0){
        for(int i=cnt-1;i>=1;i--){
            if(t[cnt]==0) break;
            if(t[i]>0) ans++,t[cnt]--,t[i]--;
        }
        if(t[cnt]>=2) ans++; 
        cnt--;
    }
    cout<<ans<<"\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}