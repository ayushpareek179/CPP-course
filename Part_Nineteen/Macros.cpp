
#include <iostream>
#include <cmath>
using namespace std;

#define e exp(1) //A macro to define Napier's constant
#define min(a,b,c) ((a < b && a < c)?a:(b < c) ? b:c) //minimum of three numbers
#define msg(x) #x //to convert into string

#ifndef PI //to check if PI has been defined or not
    #define PI atan(1)*4
#endif

int main()
{
    cout<<min(11,19.21,-2.45)<<"\n";
    cout<<msg(Napier's constant's fourth power is: )<<pow(e,4)<<"\n";
    cout<<msg(The ratio between circumference and diameter of a cirlce is: )<<PI<<"\n";
    return 0;
}