#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
vector<int> s;
bool check(int mid)
{
    int lst=0;
    for(int i:s){
        lst=min(lst,i);
        if(mid<i-lst-1) return false;
        else if(mid>i-lst-1) lst=i+mid;
        else lst=i+mid-1;
    }
    if(lst<n) return false;
    return true;
}
void solve()
{
    cin>>n;
    int l=0,r=n;
    s.clear();
    for(int i=1;i<=n;i++){
        char c;
        cin>>c;
        if(c=='1') s.push_back(i);
    }
    if(s.size()==n){
        cout<<"0\n";
        return;
    }
    while(l<r){
        int mid=(l+r)/2;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    cout<<l<<"\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int tt;
    cin>>tt;
    while(tt--){
        solve();
    }
    return 0;
}