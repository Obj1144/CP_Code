//also D2
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[20000007],cnt[20000007];
bool isnp[20000007];
vector<int> primes;
void euler()
{
    for(int i=2;i<=2e7;i++){
        if(!isnp[i]) primes.push_back(i);
        for(int p:primes){
            if(i*p>2e7) break;
            isnp[i*p]=true;
            if(i%p==0) break;
        } 
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    euler();
    ll n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        for(int j=1;j*j<=x;j++){
            if(x%j) continue;
            cnt[j]++;
            if(j*j!=x) cnt[x/j]++;
        }
    }
    ll ans=0;
    dp[1]=n;
    for(int i=1;i<=2e7;i++){
        for(int k:primes){
            ll j=k*i;
            if(j>2e7) break;
            dp[j]=max(dp[j],dp[i]+(j-i)*cnt[j]);
        }
        ans=max(ans,dp[i]);
    }
    cout<<ans<<"\n";
    return 0;
}