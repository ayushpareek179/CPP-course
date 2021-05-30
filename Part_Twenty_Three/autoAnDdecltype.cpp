//To demonstrate auto() and decltype()
#include <iostream>
#include <cmath>
using namespace std;

double pi()
{
    return atan(1)*4;
}

int main()
{
    cout<<"Enter the radius\n";
    double r; cin>>r;
    //auto r; - not permitted
    auto circumference = 2*pi()*r;
    cout<<"Circumference for a circle with radius "<<r<<" units is "<<circumference<<" units\n";

    auto rand = circumference + 'A' - '8'*2;; //unknown type
    cout<<rand<<"\n";

    decltype(r) d = circumference/2*r; //decltype() for saving time
    cout<<"Area: "<<d<<"\n";
    return 0;
}