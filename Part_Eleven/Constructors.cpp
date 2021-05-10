//Class with constructors
//Deep-copy constructor implemented
#include <iostream>
#include <cmath>
class Rectangle
{
    double* p;
    /*Rectangle() - default constructor, won't be needed
    {
        length = 0;
        breadth = 0;
    }*/
    public:
    Rectangle(double l = 0, double b = 0) //default parameters 
    {//parameterized constructor mimics the default one, if needed
        p = new double[2];
        setLength(l);
        setBreadth(b);
    }
    Rectangle(Rectangle& rec)
    {
        p = new double[2];
        p[0] = rec.p[0];
        p[1] = rec.p[1];
    }
    void setLength(double l) //length mutator
    {
        if(l < 0)
            p[0] = -l;
        else 
            p[0] = l;
    }
    void setBreadth(double b) //breadth mutator
    {
        if(b < 0)
            p[1] = -b;
        else 
            p[1] = b;
    }
    double getLength() //length accessor
    {
        return p[0];
    }
    double getBreadth() //breadth accessor
    {
        return p[1];
    }
    double area()
    {
        return p[0]*p[1];
    }
    double perimeter()
    {
        return 2*(p[0]+p[1]);
    }
    double diagonal()
    {
        return sqrt(p[0]*p[0] + p[1]*p[1]);
    }
};

using namespace std;

int main()
{
    Rectangle *ptr = new Rectangle(5,6); //length = 5, breadth = 6
    Rectangle r2(*ptr); //works
    
    cout<<"Area of rectangle: "<<r2.area()<<"\n";
    cout<<"Perimeter of rectangle: "<<r2.perimeter()<<"\n";
    cout<<"Diagonal for rectangle is: "<<r2.diagonal()<<"\n";
    cout<<"Length of rectangle is: "<<r2.getLength()<<"\n";
    cout<<"Breadth of rectangle is: "<<r2.getBreadth()<<"\n";
    
    return 0;
}
