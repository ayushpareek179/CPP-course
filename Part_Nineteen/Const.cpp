//const keyword
#include <iostream>
using namespace std;

class Immutable
{
    private:
    int x, y;
    public:
    Immutable(int a = 0, int b = 0)
    {
        x = a;
        y = b;
    }
    void display() const //almost like throw(int)
    {
        /* Not allowed since the functiuon cannot change values
        x++;
        y *= 10;
        */
       int z = 231; z++; //allowed for local variables
       cout<<"Function which cannot mutate data members holds:\n";
       cout<<x<<" "<<y<<" "<<z<<"\n"; 
    }
};

void unmodifiablePointer()
{
    int var = 10, ide = 12;
    const int* const ptr = &var;
    /*Not allowed:
        ptr = &ide; - address held within cannot be changed
        --(*ptr); - value held within cannot be changed
    */
   cout<<"Value held in constant pointer with constant address: "<<var<<"\n";
}

void Refconst(const int& a) //const - not allowed for non-member functions 
{
    //a++; - not allowed
    cout<<"Unmodifiable parameter in inline function has the value: "<<a<<"\n";
}

void constFuncs()
{
    Immutable obj(171, 241);
    obj.display();

    int x = 23;
    Refconst(x);
}

void constAndPtr()
{
    const int x = 12; int y = 3;
    int const z = 49; //works just like above
    /* Not allowed:
    ++x; x = y;*/
    cout<<"Value held in constant identifier: "<<x<<"\n"; //allowed

    //int* ptr = &x; - constant identifier cannot be pointed to be a normal pointer
    //(*ptr)++; - read only, cannot write
    const int* ptr = &y;
    ptr = &z; //allowed
    cout<<"Value held in pointer with unmodifiable value: "<<*ptr<<"\n";
    
    int* const ptr1 = &y; //pointer with constant address
    //ptr1 = &x; - not permitted 
    cout<<"Value held in pointer with unmodifiable address: "<<*ptr1<<"\n";
}

int main()
{
    constAndPtr(); //constant identifiers, constant pointers and pointers with unchangeable address
    unmodifiablePointer(); //pointers which are constant, both in address stored and value referred to
    constFuncs(); //class with function that cannot mutate class' data members and function with constant reference parameter
    return 0;
}