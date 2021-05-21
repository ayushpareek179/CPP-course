//Real-life comparison
#include <iostream>
using namespace std;

class pet
{
    public:
    void eat()
    {
        cout<<"Pets eat\n";
    }
    void sleep()
    {
        cout<<"Pets sleep\n";
    }
    void excrete()
    {
        cout<<"Pets excrete\n";
    }
};

class dog:public pet 
{
    public:
    void barks()
    {
        cout<<"Dogs bark\n";
    }
    void walk()
    {
        cout<<"Dogs go for a walk\n";
    }
};

int main()
{
    dog p; pet* d = &p;
    //Is dog a pet? Yes!
    d->eat(); d->excrete(); d->sleep();
    //dog* p = new pet(); - A pet isn't a dog necessarily
    p.barks(); p.walk();
    return 0;
}