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
    s="?"+s;
    s=s+"?";
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(s[i]!='a') continue;
        if(s[i-1]=='a'||s[i+1]=='a') ans++;
    }
    cout<<ans<<"\n";
    return 0;
}