#include<bits/stdc++.h>
using namespace std;
using ll=long long;

void solve()
{
    int mi=1e9;
    int n;
    cin>>n;
    vector<int> s(n+1);
    vector<int> tag(10005,0);
    for(int i=1;i<=n;i++) cin>>s[i];
    int ans=0;
    stack<int> st;
    tag[0]=1;
    for(int i=1;i<=n;i++){
        if(tag[s[i]]) s[i]=0;
        if(!st.empty()&&st.top()>s[i]){
            while(!st.empty()){
                int x=st.top();
                st.pop();
                if(tag[x]==0) tag[x]=1,ans++;
            }
        }
        st.push(s[i]);
    }
    cout<<ans<<"\n";
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
}