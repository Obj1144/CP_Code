#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int dp[600];
int vis[600];
int foo(int x,int pos)
{
    int res=x;
    if(pos==1){
        res^=(1<<8);
        res^=(1<<7);
        res^=(1<<5);
    }
    else if(pos==2){
        res^=(1<<8);
        res^=(1<<7);
        res^=(1<<6);
        res^=(1<<4);
    }
    else if(pos==3){
        res^=(1<<6);
        res^=(1<<7);
        res^=(1<<3);
    }
    else if(pos==4){
        res^=(1<<8);
        res^=(1<<5);
        res^=(1<<2);
        res^=(1<<4);
    }
    else if(pos==5){
        res^=(1<<4);
        res^=(1<<5);
        res^=(1<<3);
        res^=(1<<7);
        res^=(1<<1);
    }
    else if(pos==6){
        res^=(1<<6);
        res^=(1<<3);
        res^=(1<<0);
        res^=(1<<4);
    }
    else if(pos==7){
        res^=(1<<5);
        res^=(1<<2);
        res^=(1<<1);
    }
    else if(pos==8){
        res^=(1<<1);
        res^=(1<<4);
        res^=(1<<2);
        res^=(1<<0);
    }
    else if(pos==9){
        res^=(1<<1);
        res^=(1<<3);
        res^=(1<<0);
    }
    return res;
}
void bfs()
{
    queue<pair<int,int>> q;
    q.push({0,0});
    while(!q.empty()){
        int x=q.front().first,y=q.front().second;
        q.pop();
        if(vis[x]) continue;
        vis[x]=1;
        dp[x]=y;
        for(int i=1;i<=9;i++){
            int k=foo(x,i);
            if(!vis[k]) q.push({k,y+1});
        }
    }
}
void solve()
{
    int n=0;
    for(int i=1;i<=9;i++){
        int x;
        cin>>x;
        if(x==1)n+=(1<<(9-i));
    }
    for(int i=0;i<600;i++) dp[i]=1e9+7;
    dp[0]=0;
    bfs();
    cout<<dp[n]<<"\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}