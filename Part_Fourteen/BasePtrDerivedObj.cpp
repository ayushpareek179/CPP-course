//To depict pointer to a derived class objeof base class type
#include <iostream>
using namespace std;
class parent
{
    public:
    void func()
    {
        cout<<"Base's function\n";
    }
};
class child:public parent
{
    public:
    void meth()
    {
        cout<<"Derived's function\n";
    }
};
int main()
{
    child c; 
    //parent* pa = &c; - Works as well
    parent* p = new child();
    p->func();
    //p->meth() - doesn't work
    //c.meth(); - works
    return 0;
}