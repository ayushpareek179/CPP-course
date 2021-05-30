#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

#define PI atan(1)*4

int main()
{
    cout<<"Enter a number:\n";
    int n; cin>>n;
    cout<<"\nHexadecimal equivalent: "<<hex<<n<<"\n";
    cout<<"Octadecimal equivalent: "<<oct<<n<<"\n";

    cout<<"PI is usually displayed as: "<<dec<<PI<<"\n";
    cout<<"However, it can be displayed as: "<<fixed<<setprecision(8)<<PI<<"\n";

    cout<<setw(10)<<setfill('@')<<right<<"Soap\n";
    
    return 0;
}