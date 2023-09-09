#include<bits/stdc++.h>
using namespace std;
using ll=long long;
void solve()
{
    ll l,m,n;
    cin>>l>>m>>n;
    string str;
    cin>>str;
    str="?"+str+"?";
    vector<ll> s;
    int cot=0;
    for(int i=l;i>=1;i--){
        if(str[i]=='*') cot++;
        else if(str[i+1]=='*')s.push_back(cot*m+1),cot=0;
    }
    if(cot>0) s.push_back(cot*m);
    vector<ll> cnt(s.size()+1,-1);
    cnt[0]=1;
    n--;
    for(int i=1;i<s.size();i++){
        cnt[i]=s[i-1]*cnt[i-1];
        if(cnt[i]>n) break;
    }
    queue<int> ans;
    for(int i=s.size()-1;i>=0;i--){
        if(cnt[i]<=0){
            ans.push(0);
            continue;
        }
            ans.push(n/cnt[i]);
            n%=cnt[i];  
    }
    for(int i=1;i<=l;i++){
        if(str[i]!='*') cout<<str[i];
        else if(str[i]=='*'&&str[i-1]!='*'){
            int x=ans.front();
            ans.pop();
            for(int j=1;j<=x;j++) cout<<"y";
        }
    }
    cout<<"\n";
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
}