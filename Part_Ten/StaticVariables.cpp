/*To explain the difference between static and other local variables
and their similarity with global variables*/
#include <iostream>
using namespace std;

int g = 10;

int* func(int iter)
{
    static int s = 10; //initialized only once
    int a = 1; //usual local variable
    s++; g++; 
    cout<<"Iteration number "<<iter<<"\n";
    cout<<"Static variable: "<<s<<"\n"<<"Local variable: "<<a<<"\n";
    cout<<"Global variable: "<<g<<"\n\n";
    return &s;
}

int main()
{
    int* p; //s = 5; - This does not work
    for(int i = 1; i < 5; i++)
    {
        p = func(i); //to call multiple times
        //cout<<*p<<"\n"; - This works
    }
    //The output shows how similar the static and global functions are
    return 0;
}