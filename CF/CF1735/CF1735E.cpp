#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll d1[1005],d2[1005],n;
struct node{
    multiset<int> s;
    void clear(){s.clear();};
    int size(){return s.size();}
    int max(){return *prev(s.end());}
    int min(){return *s.begin();}
    void add(int x){s.insert(x);}
    void erase(int x){s.erase(s.find(x));}
    bool count(int x){return s.find(x)!=s.end();}    
}s1,s2;
bool func(int dis)
{
    s1.clear();s2.clear();
    int p1=0,p2=dis;
    for(int i=1;i<=n;i++) s1.add(d1[i]);
    for(int i=1;i<=n;i++) s2.add(d2[i]);
    vector<int> ans;
    while (s1.size()&&s2.size()&&max(s1.max(),s2.max())>dis)
    {
        if(s1.max()>s2.max()){
            int x=s1.max();
            int y=x-dis;
            if(!s2.count(y)) return false;
            s1.erase(x),s2.erase(y);
            ans.push_back(x);
        }
        else{
            int x=s2.max();
            int y=x-dis;
            if(!s1.count(y)) return false;
            s1.erase(y),s2.erase(x);
            ans.push_back(dis-x);
        }
    }
    while(s1.size()&&s2.size()){
        if(s1.min()+s2.max()!=dis) return false;
        ans.push_back(s1.min());
        s1.erase(s1.min()),s2.erase(s2.max());
    }
    sort(ans.begin(),ans.end());
    int k=max(-ans[0],0);
    cout<<"Yes\n";
    for(int i:ans){
        cout<<i+k<<" ";
    }
    cout<<"\n";
    cout<<p1+k<<" "<<p2+k<<"\n";
    return true;
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>d1[i];
    for(int i=1;i<=n;i++) cin>>d2[i];
    for(int i=1;i<=n;i++){
        if(func(d1[1]+d2[i])) return;
        if(func(abs(d1[1]-d2[i]))) return;
    }
    cout<<"No\n";
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