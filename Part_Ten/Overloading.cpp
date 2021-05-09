//To demonstrate overloading using area of some 2D and 3D shapes
#include <iostream>
#include <cmath>
using namespace std;

#define PI atan(1)*4

double area(double radius) //Area of circle
{
    if(radius <= 0)
    return -1;
    return radius*radius*PI;
}

double area(double radius, double height) //Total area of cone
{
    if(height <= 0)
        return -1;
    
    double CSA = PI*radius*sqrt(radius*radius + height*height);
    double CA = area(radius);
    
    if(CA == -1)
        return -1;
    return (CSA + CA);
}

double area(float radius, float height) //Total area of cylinder
{
    if(height <= 0 || radius <= 0)
        return -1;
    double CSA = PI*radius*height;
    return (CSA + 2*area(radius));
}

double area(float radius) //Area of sphere
{
    if(radius <= 0)
        return -1;
    return 4*area((double)radius);
}

double area(float side1, double side2) //Area of rectangle
{
    if(side1 <= 0 || side2 <= 0)
        return -1;
    return (double)side1*side2;
}

int main()
{
    cout<<"Menu:\n1. Total area of cylinder\n2. Total area of cone\n3. Total area of sphere\n";
    cout<<"4. Area of circle\n5. Area of rectangle\n0. All options\n";   

    while(true)
    {
        cout<<"Enter your choice\n";
        int r; cin>>r;
        switch(r)
        {
            case 0:
            case 1:
            {
                cout<<"Enter radius and height of cylinder\n";
                float x, y; cin>>x>>y;
                double ar = area(x,y);
                if(ar == -1)
                    cout<<"Invalid input\n";
                cout<<"Total area of cylinder is: "<<ar<<" units\n";
                if(r == 1)
                    break;
            }
            case 2:
            {
                cout<<"Enter radius and height of cone\n";
                double x, y; cin>>x>>y;
                double ar = area(x,y);
                if(ar == -1)
                    cout<<"Invalid input\n";
                cout<<"Total area of cone is: "<<ar<<" units\n";
                if(r == 2)
                    break;
            }
            case 3:
            {
                cout<<"Enter radius of sphere\n";
                float x; cin>>x;
                double ar = area(x);
                if(ar == -1)
                    cout<<"Invalid input\n";
                cout<<"Area of sphere is: "<<ar<<" units\n";
                if(r == 3)
                    break;
            }
            case 4:
            {
                cout<<"Enter the radius of circle\n";
                double x; cin>>x;
                double ar = area(x);
                if(ar == -1)
                    cout<<"Invalid input\n";
                cout<<"Area of circle is: "<<ar<<" units\n";
                if(r == 4)
                    break;
            }
            case 5:
            {
                cout<<"Enter length and breadth of rectangle\n";
                float x; double y; cin>>x>>y;
                double ar = area(x,y);
                if(ar == -1)
                    cout<<"Invalid input\n";
                cout<<"Area of rectangle is: "<<ar<<" units\n";
                if(r == 5 || r == 0)
                    break;
            }
            default: cout<<"Invalid choice\n";
        }
        cout<<"\nTo continue, press c\n";
        char c; cin>>c;
        if(c != 'c')
            break;
    }
    return 0;
}