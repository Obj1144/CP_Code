#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
struct node{
    int ch[27];
    int fail;
    int ans;
}tr[200005];
vector<int> g[200005];
int ans[200005];
queue<int> sid;
int cnt=0;
void insert(string& s)
{
    int u=0;
    for(char c:s){
        if(tr[u].ch[c-'a']==0) tr[u].ch[c-'a']=++cnt;
        u=tr[u].ch[c-'a'];
    }
    sid.push(u);
}
void build()
{
    queue<int> q;
    for(int i=0;i<26;i++)
        if(tr[0].ch[i]) q.push(tr[0].ch[i]);
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(int i=0;i<26;i++){
            if(tr[x].ch[i]){
                tr[tr[x].ch[i]].fail=tr[tr[x].fail].ch[i];
                q.push(tr[x].ch[i]);
                g[tr[tr[x].fail].ch[i]].push_back(tr[x].ch[i]);
            }
            else{
                tr[x].ch[i]=tr[tr[x].fail].ch[i];
            }
        }
    }
}
void query(string& s)
{
    int u=0;
    for(char c:s){
        u=tr[u].ch[c-'a'];
        ans[u]++;
    }
}
void dfs(int x)
{
    for(int i:g[x]){
        dfs(i);
        ans[x]+=ans[i];
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        insert(s);
    }
    build();
    string s;
    cin>>s;
    query(s);
    for(int i=0;i<26;i++){
        if(tr[0].ch[i]) dfs(tr[0].ch[i]);
    }
    while(!sid.empty()){
        int x=sid.front();
        sid.pop();
        cout<<ans[x]<<"\n";
    }
    return 0;
}