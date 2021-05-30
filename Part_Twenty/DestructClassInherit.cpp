
#include <iostream>
using namespace std;

class base
{
    public:
    base()
    {
        cout<<"\nBase's constructor called\n";
    }
    virtual ~base()
    {
        cout<<"Base's destructor called\n";
    }
};

class derived:public base 
{
    public:
    derived():base() //optional to write :base() in this case
    {
        cout<<"Derived's constructor called\n";
    }
    ~derived()
    {
        cout<<"Derived's destructor called\n";
    }
};

void taskmaster()
{
    derived* d = new derived();
    //no need to call the destructor explicitly for object/pointer in stack
    delete d;
}

void VirtualTaskmaster()
{
    base* p = new derived();
    /*
    Base class pointer to derived class object
    1. Base and derived class constructors (in this order) are called usually
    2. For normally-written code, base class' destructor is called solely
    3. Writing "virtual" enables normal functioning, that is, derived destructor followed by base's
    */
    delete p;
}

int main()
{
    taskmaster();
    VirtualTaskmaster();
    return 0;
}