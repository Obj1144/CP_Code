#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
map<string,int> mp;
int mx=0;
void add(string& s)
{
    string t=s;
    int k=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='*') k=i;
    }
    for(int i=0;i<26;i++){
        t[k]='a'+i;
        mp[t]++;
        mx=max(mx,mp[t]);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        add(s);
    }
    vector<string> s;
    for(auto i:mp){
        if(i.second==mx) s.push_back(i.first);
    }
    sort(s.begin(),s.end());
    cout<<s[0]<<" "<<mx<<"\n";
    return 0;
}