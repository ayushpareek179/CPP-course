//To demonstrate function overriding using a circle-cylinder example
#include <iostream>
#include <cmath>

#define PI atan(1)*4
using namespace std;

class Circle
{
    private:
    double radius;
    public:
    Circle(double radius = 0.0)
    {
        if(radius >= 0)
            this->radius = radius;
        else 
            this->radius = 0;
    }
    double getRadius(){return radius;}
    double getArea();
    double getCircumference();
    ~Circle(){};
};
double Circle::getArea()
{
    return PI*radius*radius;
}
double Circle::getCircumference()
{
    return 2*radius*PI;
}

class Cylinder:public Circle
{
    private:
    double height;
    public:
    Cylinder(double radius = 0.0, double height = 0.0):Circle(radius)
    {
        if(height >= 0)
            this->height = height;
        else 
            height = 0;
    }
    double getHeight(){return height;}
    double getVolume();
    double getCurvedSurfaceArea();
    double getArea(); //overriding
    double getLateralArea();
    double getLateralPerimeter();
};
double Cylinder::getVolume()
{
    return height*Circle::getArea();
}
double Cylinder::getCurvedSurfaceArea()
{
    return 2*getRadius()*height*PI;
}
double Cylinder::getArea()
{
    return (getCurvedSurfaceArea()+2*Circle::getArea());
}
double Cylinder::getLateralArea()
{
    return getHeight()*2*getRadius();
}
double Cylinder::getLateralPerimeter()
{
    return 2*(2*getRadius()+getHeight());
}

int main()
{
    cout<<"Enter the radius and height of cylinder\n";
    double r, h; cin>>r>>h;
    Cylinder c(r,h);

    cout<<"Height of cylinder: "<<c.getHeight()<<" units\n";
    cout<<"Radius of cylinder: "<<c.getRadius()<<" units\n";
    cout<<"Volume of cylinder: "<<c.getVolume()<<" cubic units\n";
    cout<<"Perimeter of cylinder on 2D plane (vertical cross section): "<<c.getCircumference()<<" units\n";
    cout<<"Perimeter of cylinder on 2D plane (lateral cross section): "<<c.getLateralPerimeter()<<" units\n";
    cout<<"Total area of cylinder: "<<c.getArea()<<" squared units\n";
    cout<<"Curved surface area of cylinder: "<<c.getCurvedSurfaceArea()<<" squared units\n";
    cout<<"Area of cylinder on 2D plane (vertical cross section): "<<c.Circle::getArea()<<" squared units\n";
    cout<<"Area of cylinder on 2D plane (lateral cross section): "<<c.getLateralArea()<<" squared units\n";

    return 0;
}