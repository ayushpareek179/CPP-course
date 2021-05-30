#include <iostream>
using namespace std;
class MyException: public exception
{
    public:
    string what()
    {
        return "Division by zero";
    }
};
double division(double x, double y)throw(MyException)
{
    if(x == 0)
        throw MyException();
    return y/x;
}

int main()
{
    cout<<"Enter the divisor and dividend\n";
    double c, d; cin>>c>>d;
    try 
    {
        double ans = division(c,d);
        cout<<d<<"/"<<c<<" = "<<ans<<"\n";
    }
    catch(MyException e)
    {
        cerr<<e.what()<<"\n";
    }    
    cout<<"Program terminated\n";
    return 0;
}