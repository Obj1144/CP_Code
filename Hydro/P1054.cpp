#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    vector<int> s(n+2,0);
    for(int i=1;i<=n;i++) cin>>s[i];
    int ans=n,cot=0;
    for(int i=1;i<=n;i++){
        if(i!=s[i]) cot++;
    }
    ans=min(ans,cot+2);
    for(int i=1;i<=n;i++){
        int res=cot;
        if(s[i]==i-1){
            res--;
            if(s[i-1]==i) res--;
            ans=min(ans,res);
        }
        res=cot;
        if(s[i]==i+1){
            res--;
            if(s[i-1]==i) res--;
            ans=min(ans,res);
        }        
    }
    cout<<ans<<"\n";
}