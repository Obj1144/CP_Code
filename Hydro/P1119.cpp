#include<bits/stdc++.h>
using namespace std;
using ll=long long;

bool isnp[1000005];
vector<int> primes;
int mp[1000005],tp[1000005];

void euler()
{
    for(int i=2;i<=1e6;i++){
        if(!isnp[i]) primes.push_back(i),tp[i]=i;
        for(int& p:primes){
            if(i*p>1e6) break;
            isnp[i*p]=true;
            tp[i*p]=p;
            if(i%p==0) break;
        }
    }

    for(int i=2;i<=1e6;i++){
        int res=1,k=i;
        while(tp[k]>0){
            res=max(res,tp[k]);
            k/=tp[k];
        }
        mp[i]=res;
    }
}

int cal(int x)
{
    if(mp[x]) return x-x/mp[x];
    return 0;
}

void solve()
{
    int n,k;
    cin>>n>>k;
    priority_queue<pair<int,int>> q;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        q.push({cal(x),x});
    }
    while(k--){
        int x=q.top().second;
        if(x==1) break;
        q.pop();
        x/=mp[x];   
        q.push({cal(x),x});
    }
    ll ans=0;
    while(!q.empty()){
        ans+=q.top().second;
        q.pop();
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