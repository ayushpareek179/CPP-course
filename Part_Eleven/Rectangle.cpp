//The "ideal" Rectangle class
#include <iostream>
#include <cmath>
using namespace std;
class Rectangle
{
    private:
    double length;
    double breadth;
    public:
    Rectangle(double, double); //Parameterised constructor
    Rectangle(Rectangle&); //copy constructor
    //accessors
    double getLength();
    double getBreadth();
    //mutators
    void setLength(double);
    void setBreadth(double);
    //facilitators
    double area();
    double perimeter();
    double diagonal();
    //inspector/enquiry
    bool isSquare();
    //destructor
    ~Rectangle();
};
int main()
{
    cout<<"Enter the length and breadth of rectangle\n";
    double l, b;cin>>l>>b;
    Rectangle* r1 = new Rectangle(l,b);
    
    cout<<"Length of rectangle is: "<<r1->getLength()<<"\n";
    cout<<"Breadth of rectangle is: "<<r1->getBreadth()<<"\n";
    cout<<"Area of rectangle is: "<<r1->area()<<"\n";
    cout<<"Perimeter of rectangle is: "<<r1->perimeter()<<"\n";
    cout<<"Diagonal of rectangle is: "<<r1->diagonal()<<"\n";
    if(r1->isSquare())
        cout<<"The rectangle is a square\n";
    r1->~Rectangle(); //for 'new', required explicitly
    return 0;
}
Rectangle::Rectangle(double length = 0, double breadth = 0)
{
    setLength(length);
    setBreadth(breadth);
}
Rectangle::Rectangle(Rectangle& rec)
{
    length = rec.length;
    breadth = rec.breadth;
}
void Rectangle::setLength(double length)
{
    if(length < 0)
        this->length = -length;
    else 
        this->length = length;
}
void Rectangle::setBreadth(double breadth)
{
    if(breadth < 0)
        this->breadth = -breadth;
    else
        this->breadth = breadth;
}
double Rectangle::getLength()
{
    return length;
}
double Rectangle::getBreadth()
{
    return breadth;
}
double Rectangle::area()
{
    return length*breadth;
}
double Rectangle::perimeter()
{
    return 2*(length+breadth);
}
double Rectangle::diagonal()
{
    return sqrt(length*length+breadth*breadth);
}
bool Rectangle::isSquare()
{
    return length==breadth;
}
Rectangle::~Rectangle() //has to be called explicitly for object pointers in heap
{
    cout<<"Rectangle object destroyed";
}