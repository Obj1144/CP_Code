#include<bits/stdc++.h>
using namespace std;
using ll=long long;
char s[1005][1005];
bool vis[1005][1005];
int n,m;
int cot1,cot2;
pair<int,int> move(int x,int y,int op1,int op2)
{
    x+=op1,y+=op2;
    if(x>n||x<1) return {0,0};
    if(y>m||y<1) return {0,0}; 
    return {x,y};
}
void dfs(int x,int y)
{
    if(vis[x][y]) return;
    vis[x][y]=1;
    pair<int,int> p;
    p=move(x,y,1,0);
    if(p!=make_pair(0,0)&&s[x][y]==s[p.first][p.second]) dfs(p.first,p.second);

    p=move(x,y,-1,0);
    if(p!=make_pair(0,0)&&s[x][y]==s[p.first][p.second]) dfs(p.first,p.second);

    p=move(x,y,0,1);
    if(p!=make_pair(0,0)&&s[x][y]==s[p.first][p.second]) dfs(p.first,p.second);

    p=move(x,y,0,-1);
    if(p!=make_pair(0,0)&&s[x][y]==s[p.first][p.second]) dfs(p.first,p.second);
}
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>s[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            if(vis[i][j]) continue;
            cot1++;
            dfs(i,j);
        }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            if(s[i][j]=='B') s[i][j]='G';
        }
    memset(vis,0,sizeof vis);
        for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            if(vis[i][j]) continue;
            cot2++;
            dfs(i,j);
        }
    cout<<abs(cot1-cot2)<<"\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}