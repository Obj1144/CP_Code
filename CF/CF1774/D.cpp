#include<bits/stdc++.h>
using namespace std;
using ll=long long;
void solve()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int> > s(n+1,vector<int>(m+1,0));
    vector<pair<int,int>> cot(n+1,{0,0});
    int cnt=0;
    for(int i=1;i<=n;i++){
        cot[i].second=i;
        for(int j=1;j<=m;j++){
            cin>>s[i][j];
            if(s[i][j]) cot[i].first++,cnt++;
        }
    }
    if(cnt%n){
        cout<<"-1\n";
        return;
    }
    int val=cnt/n;
    cnt=0;
    for(int i=1;i<=n;i++){
        cnt+=abs(val-cot[i].first);
    }
    cnt/=2;
    cout<<cnt<<"\n";
    sort(cot.begin()+1,cot.end());
    for(int l=1,r=n;l<r;){
        for(int i=1;i<=m;i++){
            if(cot[l].first==val||cot[r].first==val) break;
            if(!s[cot[l].second][i]&&s[cot[r].second][i]){
                cout<<cot[l].second<<" "<<cot[r].second<<" "<<i<<"\n";
                s[cot[l].second][i]=1;
                s[cot[r].second][i]=0;
                cot[l].first++,cot[r].first--;
            }
        }
        if(cot[l].first==val) l++;
        if(cot[r].first==val) r--;
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