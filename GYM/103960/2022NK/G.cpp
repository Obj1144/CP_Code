#include<bits/stdc++.h>
using namespace std;
using ll =long long;
bool solve()
{
    bool p=false;
    int n;
    cin>>n;
    ll val=1,num=1,cot=0;
    for(int i=1;i<=n;i++){
        int op;
        cin>>op;
        if(p) continue;
        if(op==1) val++,num++;
        else if(op==-1){
            num--;
            if(num<=0){
                if(cot>0) cot--,num+=2,val++;
                else p=true;
            }
        }
        else{
            if(num>1) num--,cot++;
            else num++,val++;
        }
    }
    if(p) return true;
    int k=__gcd(num,val);
    num/=k;
    val/=k;
    cout<<val<<" "<<num<<"\n";
    return false;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int tt;
    cin>>tt;
    while(tt--){
        bool p=solve();
        if(p) cout<<"-1\n";
    }
}