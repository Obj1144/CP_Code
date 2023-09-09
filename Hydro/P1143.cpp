#include<bits/stdc++.h>
using namespace std;
using ll=long long;

void solve()
{
    
    ll ans=0;
    string s;
    cin>>s;
    ll left=0;
    ll res=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='(') left++;
        else if(s[i]==')'){
            left--;
        }
        else if(s[i]=='X');
        else{
            ll x=s[i]-'0';
            res=res*10+x;
            if(s[i+1]>'9'||s[i+1]<'0'){
                ans+=res*(left+1);
                res=0;
            }
        }
    }
    cout<<ans<<"\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}
