#include <iostream>
using namespace std;

double division(double divisor, double dividend)
{
    if(divisor == 0)
        throw string("Divison by zero"); //supersedes the return type
    return dividend/divisor;
} //string(" ") enables us to throw strings

int main()
{
    cout<<"Enter the divisor and dividend\n";
    double a, b; cin>>a>>b;
    try 
    {
        double c = division(a,b);
        cout<<b<<"/"<<a<<" = "<<c<<"\n";
    }
    catch(string e) //does not worry about the return type
    {//tus the utility of exception handling
        cout<<e<<"\n";
    }
    cout<<"Program terminated\n";
    return 0;
}