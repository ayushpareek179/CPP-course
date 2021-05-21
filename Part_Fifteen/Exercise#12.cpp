//Student Exercise #12
#include <iostream>
#include <cmath>

#define PI atan(1)*4
using namespace std;

void assign(double param, double* member)
{
    if(param >= 0)
        *member = param;
    else 
        *member = 0;
}

class shape
{
    public:
    virtual void area() = 0;
    virtual void perimeter() = 0;
};

class Rectangle:public shape
{
    private:
    double length;
    double breadth;
    friend void assign(double,double*); 
    
    public:
    Rectangle(double a = 0, double b = 0)
    {
        assign(a, &length);
        assign(b, &breadth);    
    } 
    void area();
    void perimeter();
};

void Rectangle::area()
{
    cout<<"The area of rectangle is: "<<length*breadth<<" square units\n";
}
void Rectangle::perimeter()
{
    cout<<"The perimeter of rectangle is: "<<2*(length+breadth)<<" units\n";
}

class Circle:public shape
{
    private:
    double radius;
    friend void assign(double,double*); 
    public:
    Circle(double r = 0)
    {
        assign(r, &radius);
    }
    void area();
    void perimeter();
};

void Circle::area()
{
    cout<<"The area of circle is: "<<PI*radius*radius<<" square units\n";
}
void Circle::perimeter()
{
    cout<<"The perimeter of circle is: "<<2*PI*radius<<" units\n";
}

int main()
{
    cout<<"Enter the length and breadth of the rectangle\n";
    double l, b; cin>>l>>b;
    shape *S = new Rectangle(l,b);
    S->area(); S->perimeter();
    delete S;

    cout<<"Enter the radius of the circle\n";
    cin>>l; S = new Circle(l);
    S->area(); S->perimeter();
    delete S;

    return 0;
}