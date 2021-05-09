//To demonstrate templates using simple operations
#include <iostream>
using namespace std;

template <class AnyType>
AnyType sum(AnyType x, AnyType y)
{
    return (x+y);
}

template <class AnyType>
AnyType minimum(AnyType x, AnyType y)
{
    return x<y?x:y;
}

int main()
{
    int a = 10, b = 2;
    float x = -123.45f, y = 29.243f;
    char i = 'a', j = 'b';
    cout<<a<<"+"<<b<<" = "<<sum(a,b)<<"\n";
    cout<<x<<"+"<<y<<" = "<<sum(x,y)<<"\n";
    cout<<"Smaller of "<<i<<" and "<<j<<" is "<<minimum(i,j)<<"\n";
    cout<<"Smaller of elephant and electricity is "<<minimum("elephant", "electricity")<<"\n";

    return 0;
}