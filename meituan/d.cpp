#include<bits/stdc++.h>
using namespace std;
using ll=long long;

void solve()
{
    string s;
    cin>>s;
    map<string,string> mp;
    string a,b;
    a=b="";
    bool p=true;//1 left=0 right;
    for(auto& i:s){
        if(i=='=') p=false;
        else if(i==';'){
            p=true;
            mp[a]=b;
            a=b="";
        }
        else{
            if(p) a+=i;
            else b+=i;
        }
    }
    int q;
    cin>>q;
    while(q--){
        string t;
        cin>>t;
        if(mp.find(t)==mp.end()) cout<<"EMPTY\n";
        else cout<<mp[t]<<"\n";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();        
}