#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,q;
    cin>>n>>q;
    vector<int> a[2];
    a[0].push_back(0),a[1].push_back(0);
    for(int i=1;i<=n;i++){
        char c;
        cin>>c;
        a[0].push_back(c-'0');
    }
    for(int i=1;i<=n;i++){
        char c;
        cin>>c;
        a[1].push_back(c-'0');
    }
    set<int> st;
    for(int i=1;i<=n;i++){
        if(a[0][i]+a[1][i]!=9) st.insert(i);
    }
    while(q--){
        int x,y,z;
        cin>>x>>y>>z;
        x--;
        int ans1,ans2;
        if(a[x][y]==z) ans1=z,ans2=0;
        else{
            if(a[x][y]+a[!x][y]>9){

            }
        }
        cout<<ans1<<" "<<ans2<<"\n";
    }
}