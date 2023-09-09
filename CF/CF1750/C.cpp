#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    int n;
    cin>>n;
    string a,b;
    cin>>a>>b;
    vector<pair<int,int>> ans;
    int cot=0,cnt=0;
    for(int i=0;i<n;i++){
        if(a[i]==b[i]) cot++;
        else cot--;
        if(a[i]=='1') cnt++;
    }
    if(abs(cot)!=n){
        cout<<"No\n";
        return;
    }
    cout<<"Yes\n";
    if(cot<0){
        ans.push_back({1,1});
        if(a[0]=='0') a[0]='1',cnt++;
        else a[0]='0',cnt--;
    }
    int lst=-1;
    for(int i=0;i<n;i++){
        if(a[i]=='1'){
            if(cnt==1){
                ans.push_back({i+1,i+1});
                ans.push_back({n,n});
                ans.push_back({1,n});
                ans.push_back({1,n-1});
                break;
            }
            else if(lst==-1) lst=i;
            else{
                ans.push_back({lst+1,lst+1});
                ans.push_back({i+1,i+1});
                cnt-=2;
                lst=-1;
            }
        }
    }
    cout<<ans.size()<<"\n";
    for(auto i:ans){
        cout<<i.first<<" "<<i.second<<"\n";
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