#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> g[10005],v[10005];
int low[10005],dfn[10005],dfncnt,sccnt,inst[10005],scc[10005],in[10005],out[10005];
stack<int> st;
void tarjan(int x)
{
    dfn[x]=low[x]=++dfncnt;
    st.push(x);
    inst[x]=1;
    for(int i:g[x]){
        if(!dfn[i]){
            tarjan(i);
            low[x]=min(low[x],low[i]);
        }
        else if(inst[i]){
            low[x]=min(low[x],dfn[i]);
        }
    }
    if(low[x]==dfn[x]){
        sccnt++;
        while(st.top()!=x){
            inst[st.top()]=0;
            scc[st.top()]=sccnt;
            st.pop();
        }
        inst[st.top()]=0;
        scc[st.top()]=sccnt;
        st.pop();
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i]) tarjan(i);
    }
    for(int i=1;i<=n;i++){
        for(int j:g[i]){
            if(scc[i]!=scc[j]){
                in[scc[j]]++;
                out[scc[i]]++;
            }
        }
    }
    int a=0,b=0;
    for(int i=1;i<=sccnt;i++){
        if(in[i]==0) a++;
        if(out[i]==0) b++;
    }
    if(sccnt==1) a=b=0;
    cout<<max(a,b)<<"\n";
    return 0;
}