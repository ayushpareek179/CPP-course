//To demonstrate destructors in C++
#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

class Class
{
    private:
    int *p, size;
    string s;
    float q;
    public:
    Class(int a = 1, string b = "Unspecified", float c = 0)
    {
        if(a > 0)
            size = a;
        else if(a < 0)
            size = -a;
        else 
            size = 1;
        p = new int[size];
        fill();
        s = b;
        q = c;
        cout<<"\nClass constructor invoked\n";
    }
    void fill()
    {
        srand(clock());
        for(int i = 0; i < size; i++)
        p[i] = rand();
    }
    void display()
    {
        cout<<"Contents of the heap array:\n"; 
        for(int i = 0; i < size; i++)
            cout<<p[i]<<" ";
        cout<<"\nString entered: "<<s<<"\n";
        cout<<"Floating point number entered: "<<q<<"\n";
    }
    ~Class()
    {
        delete []p;
        cout<<"Destructor invoked\n";
    }
};

void stackMem()
{
    Class c(5,"Stack Memory",12.34);
    c.display();
    //destructor should be evoked automatically
}

void dynMem()
{
    Class* c = new Class(10, "Heap Memory", 5.67);
    c->display();
    c->~Class(); //explicit call required
}

int main()
{
    stackMem();
    dynMem();
    return 0;
}