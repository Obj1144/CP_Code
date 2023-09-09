#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,cot,num[22];
string s;
bool check(){
    for(int i=0;i<=9;i++){
        if(num[i]==0) continue;
        if(num[i]>cot) return false;
    }
    return true;
}
void solve()
{
    cin>>n;
    cin>>s;
    ll ans=0;
    for(int i=1;i<=min(n,100);i++){
        cot=0;
        for(int j=0;j<=9;j++) num[j]=0;
        for(int j=0;j<i;j++){
            num[s[j]-'0']++;
            if(num[s[j]-'0']==1) cot++;
        }
        if(check()) ans++;
        for(int l=0,r=i;r<n;r++,l++){
            num[s[l]-'0']--;
            if(num[s[l]-'0']==0) cot--;
            num[s[r]-'0']++;
            if(num[s[r]-'0']==1) cot++;
            if(check()) ans++;
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