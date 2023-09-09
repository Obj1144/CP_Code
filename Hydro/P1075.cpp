#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int nn;
void solve()
{
    int n=nn;
    vector<int> s(n);
    for(int i=0;i<n;i++) cin>>s[i];
    sort(s.begin(),s.end());
    int k=upper_bound(s.begin(),s.end(),1)-s.begin();
    int cot=0;
    cot=k/2;
    n-=k-(k%2);
    cot+=n;
    cout<<cot<<"\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int tt;
    cin>>tt>>nn;
    while(tt--){
        solve();
    }
}
