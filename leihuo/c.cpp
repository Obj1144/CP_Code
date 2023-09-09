#include<bits/stdc++.h>
using namespace std;
using ll=long long;

struct node{
    int atk;
    int hp;
    bool sheid;
    bool chao;
    bool isuse=false;
};
int n,m,k;
ll ans=8;

void dfs(vector<node> s,vector<node> t,ll val,ll cot)
{
    if(val>=8) return;
    bool p=true;
    for(auto& i:s){
        if(i.hp>0) p=false;
    }
    if(p){
        ans=min(ans,val);
        return;
    }
    vector<node> a(s),b(t);
    p=false;
    if(cot<k){
    for(auto& i:a){
        if(i.hp>0&&i.chao) p=true;
    }
        for(auto& i:a){
            if(p&&!i.chao) continue;
            if(i.hp<=0) continue;
                for(auto& j:b){
                    if(j.isuse) continue;
                    bool js,is;
                    js=is=false;
                    if(j.atk!=0)
                    {
                    if(j.hp<=0) continue;
                    if(!j.sheid)j.hp-=i.atk;
                    else  j.sheid=false,js=true;
                    if(!i.sheid)i.hp-=j.atk;
                    else i.sheid=false,is=true;
                    }
                    j.isuse=true;
                    dfs(a,b,val,cot+1);
                    j.isuse=false;
                    if(j.atk!=0){
                    if(js) j.sheid=true;
                    else  j.hp+=i.atk;
                    if(is)  i.sheid=true;
                    else i.hp+=j.atk;
                    }
                }
        }
    }
    if(cot<k) return;
    p=true;
    while(p){
        p=false;
        for(auto& i:a){
            if(i.sheid){
                i.sheid=false;
                continue;
            }
            if(i.hp>0&&i.hp<=1) p=true;
            i.hp-=1;
        }
        for(auto& i:b){
            if(i.sheid){
                i.sheid=false;
                continue;
            }
            if(i.hp>0&&i.hp<=1) p=true;
            i.hp-=1;
        }
    }
    dfs(a,b,val+2,cot+1);
}


void solve()
{
    scanf("%d",&n);
    char c;
    vector<node> s(n);
    ll res=0,cot=0;
    getchar();
    while(scanf("%c",&c)!=EOF){
        if(c=='\n') {
            if(res!=0) s[cot].hp=res,res=0;
            break;
        }
        else if(c==' '){
            if(res!=0) s[cot].hp=res,res=0;
            cot++;
        }
        else  if(c=='('||c==')'){
            s[cot].sheid=true;
        }
        else if(c=='!'){
            s[cot].chao=true;
        }
        else if(c=='/'){
            s[cot].atk=res;
            res=0;
        }
        else{
            res=res*10+c-'0';
        }
    }
    scanf("%d",&m);
    vector<node> t(m);
    getchar();
    res=0,cot=0;
    while(scanf("%c",&c)!=EOF){
        if(c=='\n'){
            if(res!=0) t[cot].hp=res,res=0;
            break;
        }
        else if(c==' '){
            if(res!=0) t[cot].hp=res,res=0;
            cot++;
        }
        else  if(c=='('||c==')'){
            t[cot].sheid=true;
        }
        else if(c=='!'){
            t[cot].chao=true;
        }
        else if(c=='/'){
            t[cot].atk=res;
            res=0;
        }
        else{
            res=res*10+c-'0';
        }
    }
    k=min(2,m);
    dfs(s,t,0,0);
    cout<<ans<<"\n";
}

int main()
{
    int tt;
    scanf("%d",&tt);
    while(tt--)
    solve();
}