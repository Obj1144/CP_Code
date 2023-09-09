#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    int n,x;
    cin>>n>>x;
    if(n%x){
        cout<<"-1\n";
        return;
    }
    vector<bool> vis(n+1,false);
    vis[x]=true;
    vis[1]=true;
    cout<<x<<" ";
    int k=x;
    for(int i=2;i<n;i++){
        if(!vis[i]) cout<<i<<" ",vis[i]=true;
        else{
            for(int j=i;j<=n;j+=i){
                if(!vis[j]&&n%j==0){
                    cout<<j<<" ";
                    vis[j]=true;
                    break;
                }
            }
        }
    }
    cout<<1<<"\n";
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