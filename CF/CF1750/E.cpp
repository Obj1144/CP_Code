#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int pre[200005],l[200005],r[200005];
void solve()
{
    int n;
    cin>>n;
    pre[0]=0;
    for(int i=1;i<=n;i++){
        char c;
        cin>>c;
        if(c=='(') pre[i]=pre[i-1]+1;
        else pre[i]=pre[i-1]-1;
    }
    stack<int> st;
    st.push(n+2);
    pre[n+2]=-1e9;
    ll ans=0;
    for(int i=0;i<=n;i++){
        while(pre[st.top()]>pre[i]) st.pop();
        int x=-1;
        if(st.top()!=n+2) x=st.top();
        l[i]=x;
        st.push(i);
    } 
    while(!st.empty()) st.pop();
    st.push(n+1);
    pre[n+1]=-1e9;
    for(int i=n;i>=0;i--){
        while(pre[st.top()]>=pre[i]) st.pop();
        r[i]=st.top();
        st.push(i);
    }
    for(int i=0;i<=n;i++){
        ll x,y;
        x=r[i]-i,y=i-l[i];
        ans-=(((x-1)*(y-1))+x+y-2)*pre[i];
    }
    sort(pre,pre+n+1);
    for(int i=0;i<=n;i++){
        ans+=i*pre[i];
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
    return 0;
}