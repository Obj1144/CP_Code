#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    int n,m,k;
    cin>>n>>m>>k;
    int lim=n*m-3;
    set<int> st;
    int now=k;
    vector<int> s(k+1);
    for(int i=1;i<=k;i++) cin>>s[i];
    for(int i=1;i<=k;i++){
        int x=s[i];
        st.insert(x);
        if(st.size()>lim){cout<<"Tidak\n";return;}
        while(st.count(now)){
            st.erase(now);
            now--;
        }
    }
    cout<<"Ya\n";
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