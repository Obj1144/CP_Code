#include<bits/stdc++.h>
using namespace std;
using ll =long long;
void solve()
{
    int n,k;
    cin>>n>>k;
    vector<int> s(n+1);
    for(int i=1;i<=n;i++){  
        cin>>s[i];
    }
    sort(s.begin()+1,s.end());
    multiset<int> st;
    for(int i=1;i<=n;i++){
        if(i<=k) st.insert(s[i]*2);
        else st.insert(s[i]);
    }
    int ans=(*st.rbegin())-(*st.begin());
    for(int l=k-1,r=n;l>=0;l--,r--){
        auto it=st.find(s[l+1]*2);
        st.erase(it);
        st.insert(s[l+1]);
        it=st.find(s[r]);
        st.erase(it);
        st.insert(s[r]/2);
        int res=(*st.rbegin())-(*st.begin());
        ans=min(res,ans);
    }
    cout<<ans<<"\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}