#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> s(n+2,vector<int>(m+2,0));
    vector<vector<int>> dp(n+2,vector<int>(m+2,-1));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            char c;
            cin>>c;
            if(c=='#') s[i][j]=1;
        }
    auto check=[&](int x,int y)->bool{
        if(x<=0||x>n) return false;
        if(y<=0||y>m) return false;
        // if(s[x][y]) return false;
        if(s[x+1][y]||s[x-1][y]||s[x][y+1]||s[x][y-1]) return false;
        return true;
    };
    map<pair<int,int>,pair<int,int>> mp;
    deque<pair<int,int>> q;
    for(int i=1;i<=n;i++){
        if(s[i][1]){
            dp[i][1]=0;
            q.push_front({i,1});
        }
        else if(check(i,1)){
            dp[i][1]=1;
            q.push_back({i,1});         
        }
    }
    int xl[4]={1,1,-1,-1};
    int yl[4]={1,-1,-1,1};
    while(!q.empty()){
        int x=q.front().first,y=q.front().second;
        q.pop_front();
        for(int i=0;i<=3;i++){
            int xx=xl[i]+x,yy=yl[i]+y;
            if(dp[xx][yy]!=-1) continue;
            if(!check(xx,yy)) continue;
            if(s[xx][yy]){
                dp[xx][yy]=dp[x][y];
                mp[{xx,yy}]={x,y};
                q.push_front({xx,yy});
            }
            else{
                dp[xx][yy]=dp[x][y]+1;
                mp[{xx,yy}]={x,y};
                q.push_back({xx,yy});
            }
        }
    }
    ll minval=1e9+7,minidx=0;
    for(int i=1;i<=n;i++){
        if(dp[i][m]==-1) continue;
        if(dp[i][m]<=minval) minidx=i,minval=dp[i][m];
    }
    if(minidx==0){
        cout<<"No\n";
        return;
    }
    cout<<"Yes\n";
    pair<int,int> pos={minidx,m};
    while(1){
        s[pos.first][pos.second]=1;
        if(!mp.count(pos)) break;
        pos=mp[pos];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i][j]) cout<<"#";
            else cout<<".";
        }
        cout<<"\n";
    }
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