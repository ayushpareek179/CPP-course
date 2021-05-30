//To demonstrate functions with variable number of arguments
#include <iostream>
#include <stdarg.h> //for using va_list
using namespace std;

int product(int n, ...)
{
    va_list list;
    va_start(list, n);
    int p = 1;
    for(int i = 0; i < n; i++)
        p *= va_arg(list, int);
    va_end(list);
    return p;
}

int main()
{
    cout<<"Product of first five natiral numbers is: ";
    cout<<product(5, 1,2,3,4,5)<<"\n";
    return 0;
}

