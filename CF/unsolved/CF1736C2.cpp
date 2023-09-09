#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll s[200005],pre[200005],pos[200005],suf[200005],p[200005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>s[i];
    int r=1,k=1;
    for(int l=1;r<=n&&l<=n;l++){
        while((r-l+1)<=s[r]&&r<=n) r++,pos[r-1]=l;
        k=min(n+1,max(k,r+1));
        while(k<=n&&(k-l+1)<=s[k]) k++;
        if(p[r]==0) p[r]=l;
        suf[l]=suf[l-1]+(k-l);
        pos[n]=l;
        pre[l]=pre[l-1]+(r-l);

    }
    int q;
    cin>>q;
    while(q--){
        ll x,y;
        cin>>x>>y;
        ll ans=pre[n];
        if(s[x]>y&&pos[x]<=x-y){
            ans-=(pre[x-y]-pre[pos[x]-1]);
            ans+=(x-y-pos[x]+1)*(x+y-pos[x])/2;
            cout<<ans<<"\n";
        }
        else if(p[x]&&s[x]<y){
            ans-=(pre[pos[x]-1]-pre[min(x-y,p[x]-1)]);
            ans+=(suf[pos[x]-1]-suf[min(x-y,p[x]-1)]);

        }
        cout<<ans<<"\n";
    }
    return 0;
}