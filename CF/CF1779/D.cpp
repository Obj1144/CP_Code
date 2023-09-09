#include<bits/stdc++.h>
using namespace std;
using ll=long long;
bool solve()
{
    int n;
    cin>>n;
    vector<int> a(n+1);
    vector<pair<int,int>> b(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i].first,b[i].second=i;
    int m;
    cin>>m;
    map<int,int> mp;
    for(int i=1;i<=m;i++){
        int x;
        cin>>x;
        mp[x]++;
    }
    for(int i=1;i<=n;i++){
        if(a[i]<b[i].first) return false;
        if(mp.find(b[i].first)==mp.end()&&a[i]!=b[i].first) return false;
    }
    vector<int> r(n+1,n+1);
    stack<int> st;
    for(int i=n;i>=1;i--){
        while(!st.empty()&&b[i].first>=b[st.top()].first) st.pop();
        if(!st.empty()) r[i]=st.top();
        else r[i]=n+1;
        st.push(i);
    }
    sort(b.begin()+1,b.end());
    for(int i=1;i<=n;){
        vector<int> t;
        int x=b[i].first;
        while(i<=n&&b[i].first==x){
            if(a[b[i].second]!=x)t.push_back(b[i].second);
            i++;
        }
        if(mp.find(x)==mp.end()) continue;
        int cot=1;
        if(t.empty()) continue;
        for(int j=0;j<t.size()-1;j++){
            if(r[t[j]]<t[j+1]) cot++;
        }
        if(mp[x]<cot) return false;
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int tt;
    cin>>tt;
    while(tt--){
        bool p=solve();
        if(p) cout<<"YES\n";
        else cout<<"NO\n";
    }
}