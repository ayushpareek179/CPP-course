//Demonstrating in-class initialization and delegation of constructor
#include <iostream>
using namespace std;

class example
{
    private:
    int a = 4; //initialization inside 
    int b = 3; //wasn't allowed earlier
    public:
    example(int x, int y)
    {
        //some validation code
        if(x%a == 0)
            a = a*x;
        if(y%b == 0)
            b = b*y;
    }
    example():example(4,3) //calling internally
    {} //constructor delegation
    void display()
    {
        cout<<a<<" "<<b<<"\n";
    }
};

int main()
{
    example e; //default constructor is called, which delegates to param internally
    e.display();
    return 0;
}