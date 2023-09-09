#include<bits/stdc++.h>
using namespace std;
int mini=11111;
int cnt=0;
int ditu[35][35]={0};
int flag[35][35]={0};
int n,m;
void dfs(int x,int y,int number){
    flag[x][y]=1;
    if(ditu[x][y]==1){
        cnt+=1;
        if(number<mini)
            mini=number;
        return ;
    }
    if(x>n || x<1 || y<1 || y>m || ditu[x][y]==3){
        return;
    }
    if(flag[x+1][y]==0)
        dfs(x+1,y,number+1);
    if(flag[x-1][y]==0)
        dfs(x-1,y,number+1);
    if(flag[x][y+1]==0)
        dfs(x,y+1,number+1);
    if(flag[x][y-1]==0)
        dfs(x,y-1,number+1);
     
}

int main(){

    cin>>n>>m;
    int xx=0;
    int yy=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char c;
            cin>>c;
            if(c=='e'){
                ditu[i][j]=1;
            }else if (c=='.'){
                ditu[i][j]=2;
            }else if(c=='*'){
                ditu[i][j]=3;
            }else if(c=='k'){
                xx=i;
                yy=j;
                ditu[i][j]=4;
            }
        }
    }
    dfs(xx, yy, 0);
    if(cnt!=0)
        cout<<cnt<<" "<<mini;
    else
        cout<<-1;

    
    return 0;
}