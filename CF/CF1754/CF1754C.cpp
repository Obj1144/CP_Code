#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int s[200005];
void solve()
{
    int n;
    cin>>n;
    int sum=0;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        sum+=s[i];
    }
    if(sum&1) cout<<"-1\n";
    else{
        vector<int> ans;
        int lst=0,cnt=abs(sum)/2;
        for(int i=1;i<=n;i++){
            if(cnt==0) break;
            if(s[i]*sum>0&&lst<i-1){
                ans.push_back(i);
                lst=i;
                cnt--;
            } 
        }
        int j=1;
        int cot=ans.size()+(n-ans.size()*2);
        cout<<cot<<"\n";
        for(int i:ans){
            while(j<i-1) cout<<j<<" "<<j<<"\n",j++;
            cout<<i-1<<" "<<i<<"\n";
            j=i+1;
        }
        while(j<=n) cout<<j<<" "<<j<<"\n",j++;
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