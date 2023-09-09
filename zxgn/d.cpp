#include<bits/stdc++.h>
using namespace std;
using ll=long long;

unordered_map<int,bool> feb; 
vector<vector<int>> s;
map<pair<int,int>,int> pos;
vector<pair<int,pair<int,int>>> ans;
unordered_map<int,int> mp;

void solve()
{
    feb[1]=1;
    int a=1,b=1;
    while(1){
        int res=a+b;
        a=b,b=res;
        if(res>1e7) break;
        feb[res]=1;
    }
    char c;
    ll res=0;

    int cot=0;
    s.push_back(vector<int>());
    while(scanf("%c",&c)!=EOF){
        if(c=='e') break;
        if(c==' '||c=='\n'){
            s[cot].push_back(res);
            if(feb.find(res)!=feb.end()){
                if(mp.find(cot)!=mp.end()) mp[cot]++;
                else mp[cot]=1;
            }
            res=0;
        }
        else{
            res=(res*10)+c-'0';
        }
        if(c=='\n'){
            int al=*s[cot].begin(),ar=*s[cot].rbegin();
            pos.insert({{al,ar},cot});
            s.push_back(vector<int>());
            cot++;
        }
    }
    int L=-1,R=0;
    pair<int,pair<int,int>> rec;
    for(auto& i:pos){
        int l=i.first.first,r=i.first.second,p=i.second;
        if(L==-1) L=l,R=r,rec.second={L,R};
        else if(R>=l){
            rec.first++;
            R=max(R,r);
        }
        else{
            L=l,R=r;
            ans.push_back(rec);
            rec.first=0;
        }
        rec.second={L,R};
    }
    ans.push_back(rec);
    sort(ans.begin(),ans.end());
    vector<int> result;
    auto x=*ans.rbegin();
    int lll=x.second.first,rrr=x.second.second;
    for(auto& i:s){
        if(i.size()==0) break;
        if((*i.begin())>=lll&&(*i.rbegin())<=rrr){
            for(auto& j:i)
            result.push_back(j);
        }
    }
    sort(result.begin(),result.end());
    for(auto& i:result) cout<<i<<" ";
    cout<<"\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}