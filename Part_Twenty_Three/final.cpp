//To show the implications of using the 'final' keyword
#include <iostream>
using namespace std;

class base
{
    public:
    void show()
    {
        cout<<"Base's show\n";
    }
    virtual void display() final //only permitted for virtual functions
    {
        cout<<"Base's display\n";
    }
};

class home final 
{
    public:
    void print()
    {
        cout<<"Home's print\n";
    }
};

//class child:home {}; - not permitted
class child:public base
{
    public:
    void show()
    {
        //Can override
        cout<<"Child's show\n";
    }
    //void display(){} - not permitted
};

int main()
{
    base b;
    b.display(); b.show();
    home h;
    h.print();
    child c;
    c.show(); c.display();
    return 0;
}
