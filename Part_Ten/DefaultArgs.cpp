//To demonstrate default arguments using simple operations
#include <iostream>
using namespace std;

int product(int a, int b, int c = 1, int d = 1)
{
    return a*b*c*d;
}

int max(int a, int b, int c = INT_MIN, int d = INT_MIN)
{
    return a > b && a > c ? a: b > c && b > d ? b: c >d ? c:d;  
}

int main()
{
    cout<<"Enter two numbers\n";
    int a, b, c, d; cin>>a>>b;
    cout<<"\nProduct of "<<a<<" and "<<b<<" is: "<<product(a,b)<<"\n";
    cout<<"The greater number between "<<a<<" and "<<b<<" is: "<<max(a,b)<<"\n";
    
    cout<<"\nEnter three numbers\n";
    cin>>a>>b>>c;
    cout<<"\nProduct of "<<a<<", "<<b<<" and "<<c<<" is: "<<product(a,b,c)<<"\n";
    cout<<"The largest input among "<<a<<", "<<b<<" and "<<c<<" is: "<<max(a,b,c)<<"\n";

    cout<<"\nEnter four numbers\n";
    cin>>a>>b>>c>>d;
    cout<<"\nProduct of "<<a<<", "<<b<<", "<<c<<" and "<<d<<" is: "<<product(a,b,c,d)<<"\n";
    cout<<"The maximum of "<<a<<", "<<b<<", "<<c<<" and "<<d<<" is: "<<max(a,b,c,d)<<"\n";

    return 0;
}