#include<bits/stdc++.h>
using namespace std;
using ll=long long;

vector<int> primes;
bool isnp[200005];
int mp[200005];
int cnt[200005];
ll res=1;
void euler()
{
    for(int i=2;i<=2e5;i++){
        if(!isnp[i]) primes.push_back(i),mp[i]=i;
        for(int& p:primes)
        {
            if(i*p>2e5) break;
            isnp[i*p]=true;
            mp[i*p]=p;
            if(i%p==0) break;
        }
    }
}

ll sum(ll x)
{
    return x+1;
}

void foo(int x,int k)
{
    while(mp[x]){
        if(cnt[mp[x]]>0)res/=sum(cnt[mp[x]]);
        cnt[mp[x]]+=k;
        if(cnt[mp[x]]>0)res*=sum(cnt[mp[x]]);
        x/=mp[x];
    }
}

void solve()
{
    ll n,k;
    cin>>n>>k;
    vector<int> s(n+1);
    for(int i=1;i<=n;i++) cin>>s[i];
    // for(int i=1;i<=2e5;i++) cnt[i]=1;
    int l,r;
    l=r=1;
    ll ans=0;
    for(;r<=n;r++){
        foo(s[r],1);
        while(l<r&&res>=k){
            foo(s[l],-1);
            if(res<k){
                foo(s[l],1);
                break;
            }
            else{
                l++;
            }
        }
        if(res>=k) ans+=l;
    }
    cout<<ans<<"\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    euler();
    solve();
}