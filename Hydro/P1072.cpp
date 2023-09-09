#include<bits/stdc++.h>
using namespace std;
using ll=long long;
void solve()
{
    int n;
    cin>>n;
    ll up,down;
    ll black,white;
    up=down=black=white=0;
    int k=1;
    for(int i=1;i<=n;i++){
        ll x;
        cin>>x;
        if(x<0) k=-k;
        if(k>0){
            black+=down;
            white+=up;
        }
        else{
            black+=up;
            white+=down;
        }
        if(k>0) up++,white++;
        else down++,black++;
    }
    cout<<black<<" "<<white<<"\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}