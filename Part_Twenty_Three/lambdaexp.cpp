//To demonstrate lambda functions
#include <iostream>
#include <string>
using namespace std;

template <typename T>
void func(T lambda) //can be passed as a parameter
{
    lambda();
}
int main()
{
    auto f = [](double a, double b)->double{if(b != 0) return a/b; else return -1;}; //called later
    cout<<f(23.4651, -2.9761)<<"\n";

    string a = "Gdkkn";
    [&a](){for(int i = 0; i < a.length(); i++) a[i]++; cout<<a<<endl;}(); //mutates variables
    a = "Odqqn";
    cout<<([&a]()->string{for(int i = 0; i < a.length(); i++) a[i]++; return a;}())<<"\n"; //inline with cout

    a = "Cspoy";
    auto lamb = [&a](){for(int i = 0; i < a.length(); i++) a[i]--; cout<<a;}; //asserts return type itself
    func(lamb); //acts like a nested function
    return 0;
}