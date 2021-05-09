//To throw light on working of recursion
#include <iostream>
using namespace std;

int iter = 0;
int* digits(int n)
{
    static int* p = new int[10]; //max 10 digits
    if(n > 0)
    {
        cout<<n%10<<" "; //digits printed in reverse order
        digits(n/10);
        p[iter++] = n%10; //straight, as it is after the call
    }
    return p;
}

int main()
{
    int* dig = digits(5409231);
    cout<<"\n";
    for(int i = 0; i < iter; i++)
    cout<<dig[i]<<" ";
    return 0;
}