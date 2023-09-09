#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
string cal(string a,string b){
    string tmp=a;
    int m=b.length();
    for(int i=n,j=m-1;j>=0;i--,j--){
        if(a[i]=='0'&&b[j]=='1') tmp[i]='1';
    }
    return tmp;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    string s;
    cin>>s;
    s="?"+s;
    int st=1,ed=0;
    for(int i=1;i<=n;i++){
        if(s[i]=='1') break;
        st++;
    }
    if(st>n){
        cout<<"0\n";
        return 0;
    }
    for(int i=st;i<=n;i++){
        if(s[i]=='0'){
            ed=i;
            break;
        }
    }
    if(!ed){
        for(int i=1;i<=n;i++) cout<<s[i];
        cout<<"\n";
    }
    string ans=s;
    for(int i=st;i<ed;i++){
        string b=s.substr(i,n-ed+1);
        string tmp=cal(s,b);
        if(tmp>ans) ans=tmp;
    }
    bool p=true;
    for(int i=1;i<=n;i++){
        if(ans[i]=='1') p=false;
        if(p) continue;
        cout<<ans[i];
    }
    cout<<"\n";
    return 0;
}