#ifndef SKIP_LIST_CPP_
#define SKIP_LIST_CPP_

#include<iostream>
#include<string>
#include<set>
#include<time.h>
#include<functional>
#include<stdlib.h>
using namespace std;

template<typename K,typename V,typename Comp=std::less<K>>
class skip_list
{
    private:
        class skip_list_node{
            public:
            int level;
            const K key;
            V value;
            skip_list_node ** forward;
            skip_list_node():key(K()),value(V()),forward(nullptr),level(0){}
            skip_list_node(int _level,K _key,V _value,skip_list_node* nxt=nullptr):level(_level),key(_key),value(_value){
                forward=new skip_list_node* [level+1];
                for(int i=0;i<=level;i++) forward[i]=nxt;
                //给每层初始化
            }
            ~skip_list_node(){
                if(forward)
                    delete [] forward;
            }
        };
        using node=skip_list_node;
        int level;
        int length;
        static const int MAXL = 32;//最高层数
        static const int P = 4;//概率1/p
        static const int S = 0xFFFF;
        static const int PS = S / P;
        static const int INVALID = INT_MAX;
        node *head,*tail;
        Comp cmp;
        void init(){
            srand((uint32_t)time(NULL));
            level = length = 0;
            head->forward = new node * [MAXL + 1];
            for (int i = 0; i <= MAXL; i++)
                head->forward[i] = tail;        
        }
        
        int GetRandomLevel(){
            int lv = 1; while ((rand() & S) < PS) ++lv;
            return MAXL > lv ? lv : MAXL;
        }

        //私有查询函数，update是辅助数组，方便后续带修改的对外接口函数使用
        node* find(const K& key,node** update){
            node *p = head;
            for(int i=level;i>=0;i--){
                while(p->forward[i]!=tail && cmp(p->forward[i]->key,key)){
                    p=p->forward[i];
                }
                update[i]=p;
            }
            p=p->forward[0];
            return p;
        }

    public:
        class Iter{
            private:
            node *p;
            public:
            Iter(node* _p=nullptr):p(_p){}
            node* operator->(){return p;}
            node& operator *(){return *p;}
            bool operator ==(const Iter& rhs){return this->p==rhs.p;}
            bool operator !=(const Iter& rhs){return !(this->p==rhs.p);}
            Iter operator ++(){p=p->forward[0];return Iter(*p);}
            void operator ++(int){p=p->forward[0];}
            friend ostream& operator<<(ostream&os,const Iter& it){
                os<<it.p->value;
                return os;
            }
            friend istream& operator>>(istream&is,const Iter& it){
                is>>it.p->value;
                return is;
            }
        };
        Iter operator [](const K& key){
            return find(key);
        }
        skip_list():head(new node()),tail(new node()),cmp(Comp()){
            init();
        }

        skip_list(Comp _less) : head(new node()), tail(new node()),cmp{_less} {
            init();
        }

        void insert(const K& key,const V& value){
            node* update[MAXL+1];
            node* p=find(key,update);
            if(p->key==key){p->value=value;return;}
            int lv=GetRandomLevel();
            if(lv>level){
                lv=++level;
                update[lv]=head;
            }
            node *new_node=new node(lv,key,value);
            for(int i=level;i>=0;i--){
                new_node->forward[i]=update[i]->forward[i];
                update[i]->forward[i]=new_node;
            }
            length++;
        }

        bool erase(const K&key){
            node* update[MAXL+1];
            node* p=find(key,update);
            if(p==tail||p->key!=key) return false;
            for(int i=p->level;i>=0;i--){
                update[i]->forward[i]=p->forward[i];
            }
            delete p;
            while(level>0&&head->forward[level]==tail) level--;
            length--;
            return true;
        }

        Iter find(const K& key){
            node* update[MAXL+1];
            node* p=find(key,update);
            if(p==tail) return Iter(tail);
            if(p->key!=key) return Iter(tail);
            return Iter(p);
        }

        bool isexist(const K& key){
            node* update[MAXL+1];
            node* p=find(key,update);   
            if(p==tail||p->key!=key) return false;
            return true;         
        }

        Iter begin(){
            return Iter(head);
        }

        Iter end(){
            return Iter(tail);
        }
};


//--------------------------------以下为测试程序--------------------------------
int main()
{
    cout<<"添加的组数:\n";
    int tt;
    cin>>tt;
    skip_list<int,int> list;
    while(tt--){
        int k,v;
        cin>>k>>v;
        list.insert(k,v);
    }
    cout<<"查询的组数:\n";
    cin>>tt;
    while(tt--){
        int k;
        cin>>k;
        if(!list.isexist(k)) cout<<"not found\n";
        else cout<<list[k]<<"\n";
    }
}
#endif

    // {
    //     //使用lambda
    //     auto cmp = [](const string& a, const string& b) {return a.length() < b.length(); };
    //     skip_list < string, int, decltype(cmp)> list(cmp);
    //     list.insert("aab", 1321);
    //     list.insert("hello", 54342);
    //     list.insert("world", 544);
    //     for (auto it = list.begin(); it != list.end(); it++) {
    //         cout << it->key << " " << it->value << endl;
    //     }
    // }

    // cout << "==================================" << endl;
    
    // {
    //     //使用仿函数
    //     struct cmp {
    //         bool operator()(int a, int b) {
    //             return a > b;
    //         }
    //     };
    //     skip_list < int, int, cmp> list{};
    //     for (int i = 1; i <= 10; i++)list.insert(rand()%20, rand());
    //     for (auto it = list.find(10); it != list.end(); it++) {
    //         cout << it->key << " " << it->value << endl;
    //     }
    // }

    // cout << "==================================" << endl;

    // {
    //     //默认小于号
    //     skip_list<int, int>list;
    //     list.insert(1, 3);
    //     list.insert(1, 3);
    //     list.insert(4, 3);
    //     list.insert(5, 3);
    //     list.insert(1, 3);
    //     list.insert(4, 3);
    //     for (auto it = list.begin(); it != list.end();it++) {
    //         cout << it->key << " " << it->value << endl;
    //     }
       
    // }

    // {
    //     //可以添加 T && 实现move语义
    //     //添加重载 []
    // }