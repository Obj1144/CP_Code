#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int mp(char& c)
{
    if(c=='W') return 0;
    else if(c=='U') return 1;
    else if(c=='B') return 2;
    else if(c=='G') return 3;
    else if(c=='R') return 4;
    return 5;
}
bool solve()
{
    int n;
    cin>>n;
    int cnt[5]={0,0,0,0,0};
    for(int i=1;i<=n;i++){
        char c;
        cin>>c;
        cnt[mp(c)]++;
    }
    int m;
    cin>>m;
    int cot=0;
    for(int i=1;i<=m;i++){
        string s;
        cin>>s;
        for(auto& i:s){
            if(i!='O') cnt[mp(i)]--;
            else cot++;
        }
    }
    for(int i=0;i<=4;i++){
        if(cnt[i]<0) return false;
        cot-=cnt[i];
    }
    if(cot<=0) return true;
    return false;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int tt;
    cin>>tt;
    while(tt--){
        bool p=solve();
        if(p) cout<<"YES\n";
        else cout<<"NO\n";
    }
}