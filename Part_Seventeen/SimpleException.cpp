//Exception Handling
#include <iostream>
using namespace std;

int main()
{
    double divisor, dividend;
    cout<<"Enter the divisor and dividend\n";
    cin>>divisor>>dividend;
    try
    {
        if(divisor == 0)
            throw "Division by zero";
        cout<<dividend<<"/"<<divisor<<" = "<<dividend/divisor<<"\n";
    }
    catch(const char* e) //can use const char e[] but not string
    {//also, can throw numbers (int/double) and characters
        cout<<e<<"\n";
    }
    cout<<"Program terminated\n";
    return 0;
}