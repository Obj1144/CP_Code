#include<bits/stdc++.h>
using namespace std;
using ll=long long;
void solve()
{
    int q;
    cin>>q;
    ll l=1,r=1e9;
    while(q--){
        int op;
        cin>>op;
        if(op==1){
            ll a,b,n;
            cin>>a>>b>>n;
            if(a<=b&&n>1){
                cout<<"0 ";
            }
            else{
                ll L=(a-b)*(n-1)+(b+1);
                ll R=a*n-b*(n-1);
                if(L>r||R<l){
                    cout<<"0 ";
                }
                else{
                l=max(L,l);
                r=max(R,r);
                cout<<"1 ";
                }
            }
        }
        else{
            ll a,b;
            cin>>a>>b;
            if(a<=b){
                if(a>=l) cout<<"1 ";
                else cout<<"-1 ";             
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int tt;
    cin>>tt;
    while(tt--)
        solve();
}