/*To depict virtual functions, that are overridden, in inheritance
with a base class pointer pointing to a derived class oject
with a horse/donkey example*/
//Speed source - google search

#include <iostream>
using namespace std;

class horse
{
    public:
    void run()
    {
        cout<<"I run very fast, since I'm a horse!\n";
    }
    virtual void topSpeed()
    {
        cout<<"A top speed is 88 km/h\n";
    }
};

class donkey:public horse
{
    public:
    void run()
    {
        cout<<"An ass can run only so fast.\n";
    }
    void topSpeed()
    {
        cout<<"My top speed is 24 km/h\n";
    }
};

int main()
{
    donkey d; horse* h = &d; //calling a donkey "horse"
    h->run(); //as expected
    h->topSpeed(); //virtual function, donkey's run() called
    return 0;
}