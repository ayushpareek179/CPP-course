//To demonstrate function pointers
#include <iostream>
#include <cmath>
using namespace std;

#define PI atan(1)*4;

double VolCone(double radius, double height)
{ 
    return pow(radius,2)*height/3*PI;
}

double VolCylinder(double radius, double height)
{
    return radius*radius*height*PI;
}

double ArRectangle(double length, double breadth)
{
    return length*breadth;
}

int main()
{
    cout<<"Enter two positive real numbers\n";
    double a, b; cin>>a>>b;

    if(a <= 0 || b <= 0)
    {
        cout<<"Invalid input(s)!";
        return -1;
    }

    double (*fptr)(double, double); //initialization
    
    fptr = ArRectangle; //declaration
    //call #1
    cout<<"\n\nFor length = "<<a<<" units and breadth = "<<b<<" units,\nArea of Rectangle = "<<(*fptr)(a,b)<<" square units";
    
    fptr = VolCone; //reassigned
    //call#2
    cout<<"\n\nFor radius = "<<a<<" units and height = "<<b<<" units,\nVolume of Cone = "<<(*fptr)(a,b)<<" square units";
    
    fptr = VolCylinder; //reassigned again
    //call #3
    cout<<"\n\nFor radius = "<<a<<" units and height = "<<b<<" units,\nVolume of Cylinder = "<<(*fptr)(a,b)<<" square units";
    
    return 0;
}
