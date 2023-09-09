#include<iostream>
#include<string>
#include <functional>
#include<utility>
#include<memory>
#include<vector>
class A{
    public:
    int val;
    void foo(){std::cout<<"A\n";}
};

class B:public A{
    public:
    int val;
    virtual void foo(){std::cout<<"B\n";}
};

class C:public B{
    public:
    int val;
    void foo(){std::cout<<"C\n";}
};

int main()
{
    A* a=new B();
    B* b=new C();
    a->foo();
    b->foo();
    auto a="hello";
}