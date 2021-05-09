//To show various ways in which functions return
#include <iostream>
using namespace std;


int fact(int n) //returning data
{
    if(n < 0)
        return -1;
    if(n == 1 || n == 0)
        return 1;
    return n*fact(n-1);
}

float* arr(int a, int b) //returning address to data
{
    float* ptr = new float[4];
    ptr[0] = a+b;
    ptr[1] = (a-b) > 0 ? (a-b) : (b-a);
    ptr[2] = a*b;
    ptr[3] = b != 0 ? (float)a/b : -1;
    return ptr;
}

template<typename T>
T& assign(T& a) //returning reference (l-value)
{
    if(a == -1)
        cout<<"Invalid operation\n";
    else 
        cout<<a<<"\n";
    return a;
}

int main()
{
    cout<<"Enter two integers\n";
    int x, y, z; cin>>x>>y;

    cout<<"Factorial of "<<x<<" is ";
    z = fact(x); 
    assign(z) = 0; //isn't invalid   
    cout<<"Factorial of "<<y<<" is ";
    z = fact(y); 
    assign(z) = 0; //isn't invalid

    float* p = arr(x,y);
    cout<<"Basic arithmetic operations: addition, subtraction, multiplication and division\n";
    for(int i = 0; i < 3; i++)
        cout<<*(p+i)<<"\n";
    if(x == 0 || y == 0)
    assign(p[3]) = 0; //isn't invalid
    else 
    cout<<p[3];

    delete []p;
    return 0;
}