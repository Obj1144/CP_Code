#include<bits/stdc++.h>
using ll=long long;
std::map<int,int> mp;
ll mod=998244353;
void solve()
{
    int n;
    std::cin>>n;
    ll cot=0;
    ll mul=1;
    while(n--){
        int op;
        std::cin>>op;
        if(op==1){
            int y;
            std::cin>>y;
            mp[y+cot]++;
            mp[y+cot]%=mod;
        }
        else if(op==2){
            int y;
            std::cin>>y;
            cot+=y;
            cot%=mod;
        }
        else if(cot<=2e5){
            if(cot==0){
                mul*=2;
                mul%=mod;
            }
            else{
                for(int i=cot;i<=cot+2e5;i++){ mp[i+cot]+=mp[i];if(mp[i+cot]>=mod) mp[i+cot]-=mod;}
                cot*=2;
            }
        }
    }
    ll res=0;
    for(auto& i:mp){
        if(i.first>cot){
            res+=i.second;
            if(res>=mod) res-=mod;
        }
    }
    res*=mul;
    if(res>=mod) res-=mod;
    std::cout<<res<<"\n";
}
int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);std::cout.tie(0);
    solve();
    return 0;
}