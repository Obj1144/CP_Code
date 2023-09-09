#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 100005
bool isnp[N];
vector<int> primes;
int s[N];
void init()
{
    for(int i=2;i<32000;i++){
        if(!isnp[i]) primes.push_back(i);
        for(int& p:primes){
            if(p*i>=32000) break;
            isnp[p*i]=1;
            if(i%p==0) break;
        }
    }
}
void solve()
{
    int n;
    cin>>n;
    bool ans=false;
    map<int,int> mp;
    for(int i=1;i<=n;i++) cin>>s[i];
    for(int i=1;i<=n;i++){
        int x=s[i];
        for(int& p:primes){
            if(x<=1) break;
            if(x%p==0){
                if(mp[p]) ans=1;
                mp[p]=1;
            }
            while((x%p==0)) x/=p;
        }
        if(x>1){
            if(mp[x]) ans=1;
            mp[x]=1;            
        }
        if(ans) break;
    }
    if(ans) cout<<"YES\n";
    else cout<<"NO\n"; 
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    init();
    int tt;
    cin>>tt;
    while(tt--){
        solve();
    }
}
