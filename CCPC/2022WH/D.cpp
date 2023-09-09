#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
const int n=(1<<19);
ll s[20],dp[n+1];
vector<pair<int,int>> dict[20];
/*
   1  2  3
  4  5  6  7
8  9  10  11 12
 13  14 15 16
   17 18 19
*/
//dp[(1<<5)] dp[(1<<9)] dp[1<<10]
void init()
{
    dict[3].pb({1,2});
    dict[6].pb({4,5});
    dict[7].pb({5,6});
    dict[8].pb({1,4});
    dict[9].pb({2,5});
    dict[10].pb({1,5}); dict[10].pb({3,6}); dict[10].pb({8,9});
    dict[11].pb({2,6}); dict[11].pb({9,10});
    dict[12].pb({3,7}); dict[12].pb({10,11});
    dict[13].pb({5,9});
    dict[14].pb({4,9}); dict[14].pb({6,10}); 
    dict[15].pb({5,10}); dict[15].pb({7,11}); dict[15].pb({13,14});
    dict[16].pb({6,11}); dict[16].pb({14,15});
    dict[17].pb({8,13}); dict[17].pb({10,14});
    dict[18].pb({9,14}); dict[18].pb({11,15});
    dict[19].pb({10,15}); dict[19].pb({12,16}); dict[19].pb({17,18});      
    for(int i=1;i<=19;i++) cin>>s[i];
    vector<int> a(19);
    for(int k=1;k<=19;k++){
        for(int i=0;i<19;i++){
            if(19-i<=k) a[i]=1;
            else a[i]=0;
        }
        bool p=true;
        while(p){
            ll x=0;
            for(int i=0;i<19;i++){
                x<<=1;
                if(a[i]&1) x++;
            }
            for(int i=0;i<19;i++){
                ll y=(1<<i);
                if(!(x&y)) continue; 
                dp[x]=max(dp[x],dp[x-y]);
                for(auto j:dict[i+1]){
                    int aa=j.first,bb=j.second;
                    int val=s[bb];
                    aa=(1<<(aa-1)),bb=(1<<(bb-1));
                    if((x&bb)){
                        if(!(x&aa)) dp[x]=max(dp[x],dp[x-y+aa-bb]+val),dp[x-y+aa]=max(dp[x-y+aa],dp[x-y+aa-aa+y-bb]+val);
                    }
                }
            }
            p=next_permutation(a.begin(),a.end());
        }
    }
}
void solve()
{
    int x=0;
    for(int i=0;i<19;i++){
        char c;
        cin>>c;
        if(c=='#'){
            x+=(1<<i);
        }
    }
    cout<<max(0ll,dp[x])<<"\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    init();
    int tt;
    cin>>tt;
    while(tt--){
        solve();
    }
    // cout<<dp[(1<<10)+(1<<9)]<<"\n";
    // cout<<dp[(1<<5)]<<"\n";
    // cout<<dp[(1<<9)]<<"\n";
    // cout<<dp[1<<10]<<"\n";
    // cout<<dp[0]<<"\n";
    return 0;
}

    // dict[2].pb({1,3});
    // dict[4].pb({1,8});
    // dict[5].pb({1,10}); dict[5].pb({2,9}); dict[5].pb({4,6});
    // dict[6].pb({2,11}); dict[6].pb({3,10}); dict[6].pb({5,7});
    // dict[7].pb({3,12});
    // dict[9].pb({4,14}); dict[9].pb({5,13}); dict[9].pb({8,10});
    // dict[10].pb({5,15}); dict[10].pb({6,14}); dict[10].pb({9,11});
    // dict[11].pb({6,16}); dict[11].pb({7,15}); dict[11].pb({10,12});
    // dict[13].pb({8,17});
    // dict[14].pb({9,18}); dict[14].pb({10,17}); dict[14].pb({13,15});
    // dict[15].pb({10,19}); dict[15].pb({11,18}); dict[15].pb({14,16});
    // dict[16].pb({12,19});
    // dict[18].pb({17,19});