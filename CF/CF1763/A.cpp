#include<bits/stdc++.h>
void solve()
{
    int n;
    std::cin>>n;
    std::vector<int> s;
    for(int i=1;i<=n;i++){
        int x;
        std::cin>>x;
        s.push_back(x);
    }
    std::sort(s.begin(),s.end());
    int m=0;
    while((1<<(m))<=s[n-1]) m++;
    m--;
    std::vector<int> one(m+1,0),zero(m+1,1);
    for(int& i:s){
        for(int j=0;j<=m;j++){
            if((1<<j)&i) one[j]=1;
            else zero[j]=0;
        }
    }
    int res=0;
    for(int i=0;i<=m;i++){
        if(one[i]) res+=(1<<i);
        if(zero[i]) res-=(1<<i);
    }
    std::cout<<res<<"\n";
}
int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);std::cout.tie(0);
    int tt;
    std::cin>>tt;
    while(tt--){
        solve();
    }
}