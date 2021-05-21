//All class types, based on the kind of functions they have
#include <iostream>
using namespace std;

class interface
{
    public:
    virtual void kind() = 0;
    virtual void purpose() = 0; 
};

class concrete:public interface
{
    public:
    void kind()
    {
        cout<<"All functions have bodies\n";
    }
    void purpose()
    {
        cout<<"Primarily code reusability\n";
    }
};

class hybrid:public interface
{
    public:
    virtual void kind() = 0;
    void purpose()
    {
        cout<<"Polymorphism and reusability, in egalitarian measures\n";
    }
};

class Stub:public hybrid
{
    public:
    void kind()
    {
        cout<<"Overriding a hybrid class function\n";
    }
};

int main()
{
    interface *H = new Stub();//works on Grandchildren!
    H->kind(); H->purpose();
    //interface impossible; - abstract class/interface
    //hybrid heretic; - abstract class
    //concrete command; - possible
    delete H;
    H = new concrete();
    H->kind(); H->purpose();
    //H = new hybrid(); - abstract class
    return 0;
}