#include<bits/stdc++.h>
using namespace std;
using ll=long long;
void solve()
{
    int n,k;
    cin>>n>>k;
    vector<int> s(n+1,0);
    for(int i=1;i<=n;i++) cin>>s[i];
    vector<int> cnt(2002,0);
    int cot=0;
    int ans=0;
    for(int l=1,r=1;r<=n;r++){
        cnt[s[r]]++;
        if(cnt[s[r]]==1) cot++;
        if(cot>k){
            while(cot>k){
                cnt[s[l]]--;
                if(cnt[s[l]]==0) cot--;
                l++;
            }
        }
        ans=max(ans,r-l+1);
    }
    cout<<ans<<"\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}