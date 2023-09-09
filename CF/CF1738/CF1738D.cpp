#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
    int to;
    int next;
}e[200005];
int b[100005],cnt,head[100005];
void add(int u,int v){
    e[++cnt].to=v;
    e[cnt].next=head[u];
    head[u]=cnt;
}
void bfs(int ans){
    queue<int> q;
    q.push(ans);
    while(!q.empty()){
        int x=q.front();
        q.pop();
        vector<pair<int,int>> s;
        for(int i=head[x];i;i=e[i].next){
            int to=e[i].to;
            q.push(to);
            s.push_back({b[to],to});
        }
        sort(s.begin(),s.end());
        for(auto i:s){
            cout<<i.second<<" ";
        }
    }
    cout<<"\n";
}
void solve()
{
    int n,k;
    cin>>n;
    cnt=0;
    for(int i=0;i<=n+1;i++) head[i]=b[i]=0;
    k=0;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        if(x>i) k++;
        add(x,i);
        b[x]++;
    }
    int ans;
    if(head[n+1]) ans=n+1;
    else ans=0;
    cout<<k<<"\n";
    bfs(ans);
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