#include<bits/stdc++.h>
using namespace std;
using ll=long long;

ll ans=0;

void solve()
{
    int n;
    cin>>n;
    vector<ll> s(n+1),val(n+1);
    for(int i=1;i<=n;i++){
        cin>>val[i];
    }
    int cot=0;
    for(int i=1;i<=n;i++){
        char c;
        cin>>c;
        if(c=='R') s[i]=1;
        else s[i]=-1;
    }
    int m;
    cin>>m;
    vector<pair<int,int>> op(m);
    for(int i=0;i<m;i++) cin>>op[i].first;
    int cot0=0;
    for(int i=0;i<m;i++){
        cin>>op[i].second;
        if(op[i].second==0) cot0++;
    }
    sort(op.begin(),op.end());
    ll lst=0;
    vector<ll> l(n+1,0);
    cout<<cot0<<" ";
    for(auto& i:op){
        ll t=i.first-lst;
        lst=i.first;
        ans+=cot*t;
        if(i.second>0){
            cot+=s[i.second];
            l[i.second]=i.first;
            ans+=val[i.second];
        }
        else if(i.second==0){
            cout<<ans<<" ";
        }
        else{
            i.second=-i.second;
            cot-=s[i.second];
            val[i.second]+=s[i.second]*(i.first-l[i.second]);
            l[i.second]=i.first;
            ans-=val[i.second];
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}