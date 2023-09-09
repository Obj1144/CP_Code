#include<iostream>
#include<string>


template<typename K,typename V,typename Comp=std::less<K>>
class Skip_list
{
    private:
    class skip_list_node{
        private:
        skip_list_node **forward;
        const K key;
        V val;
        int level;
        skip_list_node():key(K()),val(V()),level(0),forward(nullptr){}
        skip_list_node(K& _key,V& v,int lev,skip_list_node** node=nullptr):key(_key),val(_val),level(lev){
            forward =new skip_list_node* [level+1];
            for(int i=level;i>=0;i--){
                forward[i]=node;
            }
        }
        ~skip_list_node(){delete [] forward;}
    };

    skip_list_node* head,tail;
    using node=skip_list_node;
    void init()
    {
        head=new node();
        tail=new node();
        head->forward=new node*[MAX_LEVEL+1];
        for(int i=0;i<=MAX_LEVEL;i++) head->forward[i]=tail;
                
    }

    skip_list_node* find(const K& key)
    {

    }
    public:
    const int MAX_LEVEL=32;
    const int 
};

