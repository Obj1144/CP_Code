#include<bits/stdc++.h>
using namespace std;
using ll =long long;
ll cnt[12];
ll pos[12];
void init()
{
    ll k=9;
    pos[0]=0;
    for(int i=1;i<=11;i++){
        pos[i]=pos[i-1]+k*(i+1);
        cnt[i]=cnt[i-1]+k;
        k*=10;
    }
}
void solve()
{
    ll l,r;
    cin>>l>>r;
    l--;
    ll k=upper_bound(pos,pos+11,l)-pos-1;
    ll fen=-cnt[k]/3,dou=-cnt[k]*2/3;
    l-=pos[k];
    ll p=l/((k+1)+1);
    fen-=p/3;
    dou-=(p%3)+(p/3)*2;

    k=upper_bound(pos,pos+11,r)-pos-1;
    fen+=cnt[k]/3,dou+=cnt[k]*2/3;
    r-=pos[k];
    p=r/((k+1)+1);
    fen+=p/3;
    dou+=(p%3)+(p/3)*2;
    cout<<dou<<" "<<fen<<"\n";
}
int main()
{
    init();
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int tt;
    cin>>tt;
    while(tt--){
        solve();
    }
}