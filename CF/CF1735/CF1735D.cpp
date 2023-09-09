#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s[1005];
map<string,int> mp;
int cnt[1005],n,k;
string cal(string a, string b){
    string t;
    for(int i=0;i<k;i++){
        if(a[i]==b[i]) t+=a[i];
        else{
            bool is1,is2,is0;
            is1=is2=is0=false;
            if(a[i]=='0'||b[i]=='0') is0=true;
            if(a[i]=='1'||b[i]=='1') is1=true;
            if(a[i]=='2'||b[i]=='2') is2=true;
            if(!is0) t+='0';
            else if(!is1) t+='1';
            else t+='2';
        }
    }
    return t;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        string t;
        char c;
        for(int j=1;j<=k;j++){
            cin>>c;
            t+=c;
        }
        s[i]=t;
        mp[t]=i;
    }
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++){
            string t=cal(s[i],s[j]);
            if(mp.count(t)&&mp[t]>j)
                cnt[i]++,cnt[j]++,cnt[mp[t]]++;
        }
    ll ans=0;
    for(int i=1;i<=n;i++){
        if(cnt[i]==2) ans++;
        else if(cnt[i]) ans+=(cnt[i]-1)*(cnt[i])/2;
    }
    cout<<ans<<"\n";
}