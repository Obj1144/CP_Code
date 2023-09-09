#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    s="?"+s+"?";
    for(int i=1;i<=n;i++){
        if(s[i]=='.'&&s[i-1]!='L'&&s[i+1]!='L') s[i]='C';
    }
    for(int i=1;i<=n;i++){
        cout<<s[i];
    }
    cout<<"\n";
}