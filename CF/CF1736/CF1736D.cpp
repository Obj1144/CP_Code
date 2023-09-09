#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int s[200005];
void solve()
{
    int n;
    cin>>n;
    int cot0,cot1;
    cot0=cot1=0;
    for(int i=1;i<=2*n;i++){
        char c;
        cin>>c;
        if(c=='0') s[i]=0,cot0++;
        else s[i]=1,cot1++;
    }
    if((cot0&1)){
        cout<<"-1\n";
        return;
    }
    vector<int> ans;
    int now=0;
    for(int i=1;i<2*n;i+=2){
        if(s[i]!=s[i+1]){
            if(s[i]==now) ans.push_back(i);
            else ans.push_back(i+1);
            now^=1;
        }
    }
    cout<<ans.size()<<" ";
    for(int i:ans){
        cout<<i<<" ";
    }
    cout<<"\n";
    for(int i=1;i<n*2;i+=2){
        cout<<i<<" ";
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
    return 0;
}