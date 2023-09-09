#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
map<int,int> mp;
int solve()
{
    int n;
    cin>>n;
    int cot1,cot2;
    int a,b;
    for(int i=1;i<=13;i++) mp[i]=4;
    cin>>a>>b;
    mp[a]--,mp[b]--;
    a=min(a,10),b=min(b,10);
    cot1=a+b;
    cin>>a>>b;
    mp[a]--,mp[b]--;
    a=min(a,10),b=min(b,10);
    cot2=a+b;    
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        mp[x]--;
        x=min(x,10);
        cot1+=x;
        cot2+=x;
    }
    for(auto i:mp){
        if(i.second<=0) continue;
        int x=min(10,i.first);
        if(cot2+x==23) return x;
        if(cot1+x>23&&cot2+x<23) return x;
    }
    return -1;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int ans=solve();
    cout<<ans<<"\n";
    return 0;
}