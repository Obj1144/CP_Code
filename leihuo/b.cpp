#include<bits/stdc++.h>
using namespace std;
using ll=long long;

unordered_map<ll,ll> s;
unordered_map<ll,ll> rel;
set<int> ran;

void solve()
{
    deque<pair<int,int>> q;
    ll c,n;
    cin>>c>>n;
    ll cot=c;
    ll now=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > que;
    while(n--){
        ll a,b,res;
        res=0;
        cin>>a>>b;
        if(a==-1){
            que.push({rel[b],s[b]});
            while(!que.empty()){
                if((*ran.begin())!=que.top().first) break;
                ran.erase(ran.begin());
                cot+=que.top().second;
                que.pop();
            }
            while(!q.empty()){
                int x=q.front().first,y=q.front().second;
                if(y>c&&cot==c){
                    c=y;
                    cot=0;
                    s[x]=c;
                    res+=c;
                    rel[x]=now;
                    ran.insert(now);
                    now++;
                    q.pop_front();
                }
                else if(y<=c&&cot>=y){
                    s[x]=y;
                    cot-=y;
                    res+=y;
                    rel[x]=now;
                    ran.insert(now);
                    now++;
                    q.pop_front();
                }
                else break;
            }
        }
        else{
            if(b>c&&cot==c){
                c=b;
                cot=0;
                res+=c;
                s[a]=c;
                rel[a]=now;
                ran.insert(now);
                now++;
            }
            else if(b<=c&&cot>=b){
                s[a]=b;
                res+=b;
                cot-=b;
                rel[a]=now;
                ran.insert(now);
                now++;
            }
            else{
                q.push_back({a,b});
            }
        }
        cout<<res<<"\n";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}