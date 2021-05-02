//To check if the input year is leap
#include <iostream>
using namespace std;
typedef unsigned int year;

bool isLeap(year y)
{
    if(y%4 == 0)
    {
        if(y%100 != 0 || y%400 == 0)
        return true;
    }
    return false;
}

int main()
{
    cout<<"Enter a year from common era\n";
    int a; cin>>a;

    if(a < 0) cout<<a<<"was before common era!"<<endl;
    else cout<<a<<" is "<<(isLeap(a)?"":"not ")<<"a leap year"<<endl;

    return 0;
}