#include<bits/stdc++.h>
using namespace std;
using ll=long long;

void solve()
{
    string a,b;
    cin>>a>>b;
    vector<int> s;
    int cot;
    cot=0;
    for(auto& i:a){
        int x=i-'0';
        if(x==0) cot++;
        else s.push_back(x);
    }
    sort(s.begin(),s.end());
    string t="";
    char c=s[0]+'0';
    t+=c;
    while(cot>0) t+="0",cot--;
    for(int i=1;i<s.size();i++){
        c=s[i]+'0';
        t+=c;
    }
    if(t==b) cout<<1;
    else cout<<0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int tt;
    cin>>tt;
    while(tt--)
    solve();
}