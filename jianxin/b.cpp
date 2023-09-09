#include<bits/stdc++.h>
using namespace std;
using ll=long long;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 返回当前局面色块消除后的剩余色块数
     * @param vecBlocks int整型vector<vector<>> 输入的二维数组局面
     * @return int整型
     */
    
    void dfs(vector<vector<int> >& s,int x,int y,int col){
        if(x<0||x>=s.size()) return;
        if(y<0||y>=s[0].size()) return;
        if(s[x][y]!=col) return;
        s[x][y]=0;
        dfs(s,x+1,y,col);
        dfs(s,x-1,y,col);
        dfs(s,x,y+1,col);
        dfs(s,x,y-1,col);
    }
    
    int GetLeftCount(vector<vector<int> >& vecBlocks) {
        int n=vecBlocks.size(),m=vecBlocks[0].size();
        int cot=0,blocks=0;
        for(int i=0;i<n-1;i++)
            for(int j=0;j<m-1;j++){
                if(vecBlocks[i][j]==0) continue;        
                if(vecBlocks[i][j]==vecBlocks[i][j+1]
                  &&vecBlocks[i][j]==vecBlocks[i+1][j+1]
                  &&vecBlocks[i][j]==vecBlocks[i+1][j]
                  ){
                    cot++;
                    dfs(vecBlocks,i,j,vecBlocks[i][j]);
                }
            }
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                if(vecBlocks[i][j]==0) continue;        
                blocks++;
            }
        if(cot==0) return blocks;
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<m;j++){
                if(vecBlocks[i][j]==0) continue;
                int tgt=i;
                for(int k=i+1;k<n;k++){
                    if(vecBlocks[k][j]==0) tgt=k;
                    else break;
                }
                vecBlocks[tgt][j]=vecBlocks[i][j];
                vecBlocks[i][j]=0;
            }
        }
        return GetLeftCount(vecBlocks);
    }
};

int main()
{
    vector<vector<int> > vecBlocks={{1,1,1},{2,2,1},{2,2,2},{1,1,3}};
    Solution a;
    int ans;
    ans=a.GetLeftCount(vecBlocks);
    cout<<ans<<"\n";
}