#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int s[100005],t[100005];

void solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        char c;
        cin>>c;
        s[i]=c-'a';
    }
    for(int i=1;i<=n;i++){
        t[i]=s[i]-s[i-1];
    }
    for(int i=1;i<=m;i++){
        int k;
        cin>>k;
        t[1]++;
        t[k+1]--;
    }
    int x=0;
    for(int i=1;i<=n;i++){
        x+=t[i];
        x%=26;
        x=(x+26)%26;
        char c=x+'a';
        cout<<c;
    }
    cout<<"\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}