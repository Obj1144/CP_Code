#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    vector<int> s(n+2);
    for(int i=1;i<=n;i++){
        int x;
        cin>>s[i];
    }
    s[0]=s[n+1]=0;
    int cot=n,ans=0;
    while(cot>1){
        if(cot>1) ans++;
        vector<int> t;
        t.push_back(0);
        for(int i=1;i<=s.size()-2;i++){
            if(s[i-1]>s[i]||s[i+1]>s[i]) cot--;
            else t.push_back(s[i]);
        }
        t.push_back(0);
        s=t;
    }
    cout<<ans<<"\n";
    return 0;
}