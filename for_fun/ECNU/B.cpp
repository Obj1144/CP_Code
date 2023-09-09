#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string a[1005],b[1005];
int n,m;
map<string,int> mp;
queue<int> st[1005];
string geta(int x){
    string s="";
    for(int i=1;i<=n;i++){
        s=s+a[i][x];
    }
    return s;
}
string getb(int x){
    string s="";
    for(int i=1;i<=n;i++){
        s=s+b[i][x];
    }
    return s;
}
void re(string& s){
    for(int i=0;i<s.length();i++){
        if(s[i]=='0') s[i]='1';
        else s[i]='0';
    }
}
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i]="?"+a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
        b[i]="?"+b[i];
    }
    int cot=0;
    for(int i=1;i<=m;i++){
        string s=getb(i);
        if(mp[s]==0) mp[s]=++cot; 
        st[mp[s]].push(i);
    }
    vector<int> ans1(m+1),ans2(m+1);
    for(int i=1;i<=m;i++){
        string s=geta(i);
        int k=mp[s];
        if(k!=0){
            if(st[k].size()){
                ans1[st[k].front()]=i;
                ans2[st[k].front()]=0;
                st[k].pop();
                continue;
            }
        }
        re(s);
        k=mp[s];
        if(k!=0){
            if(st[k].size()){
                ans1[st[k].front()]=i;
                ans2[st[k].front()]=1;
                st[k].pop();
                continue;
            }
        }        
    }
    for(int i=1;i<=m;i++) cout<<ans1[i]<<" ";
    cout<<"\n";
    for(int i=1;i<=m;i++) cout<<ans2[i]<<" ";
    cout<<"\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}