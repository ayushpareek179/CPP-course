//Constructors in inheritance
#include <iostream>
using namespace std;

class base
{
    public:
    base()
    {
        cout<<"Parent's default const\n";
    }
    base(int b)
    {
        cout<<"Parent's param const with value "<<b<<"\n";
    }
};
class derived:public base
{
    public:
    derived()//:base(10) - This is explicit an call
    {
        cout<<"Child's default const\n";
    }
    derived(int d)//:base(d)
    {
        cout<<"Child's param const with value "<<d<<"\n";
    }
    derived(int b, int d):base(b)
    {
        cout<<"Child's param const with value "<<d<<"\n";
    }
};

int main()
{
    derived d;
    cout<<"-------------------\n";
    derived w(5);
    cout<<"-------------------\n";
    derived g(10, 5);
    cout<<"-------------------\n";

    return 0;
}