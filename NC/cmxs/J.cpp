#include<bits/stdc++.h>
using namespace std;
using ll=long long;
vector<string> s;
ll dp[5005][800];
ll mod=1e9+7;
vector<int> t[780];
bool check(string& a,string& b){
    for(int i=0;i<a.length();i++){
        if(a[i]==b[i]) return false;
    }
    return true;
}
void solve()
{
    int m,n;
    cin>>m>>n;
    s.push_back("R");
    s.push_back("G");
    s.push_back("B");
    for(int i=2;i<=m;i++){
        vector<string> tmp;
        for(auto& j:s){
            if(j[j.length()-1]=='R') tmp.push_back(j+"B"),tmp.push_back(j+"G");
            if(j[j.length()-1]=='G') tmp.push_back(j+"R"),tmp.push_back(j+"B");
            if(j[j.length()-1]=='B') tmp.push_back(j+"G"),tmp.push_back(j+"R");
        }
        s=move(tmp);
    }
    for(int i=0;i<s.size();i++){
        for(int j=0;j<s.size();j++){
            if(check(s[i],s[j])) t[i].push_back(j); 
        }
    }
    for(int i=0;i<s.size();i++) dp[1][i]=1;
    for(int i=2;i<=n;i++)
        for(int j=0;j<s.size();j++){
            for(auto& k:t[j]){
                dp[i][j]+=dp[i-1][k];
                dp[i][j]%=mod;
            }
        } 
    ll ans=0;
    for(int i=0;i<s.size();i++) ans+=dp[n][i],ans%=mod;
    cout<<ans<<"\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}