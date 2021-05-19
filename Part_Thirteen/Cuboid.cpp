//To demonstrate inheritance via a basic example
#include <iostream>
using namespace std;

class Rectangle
{
    private:
    double length;
    double breadth;
    public:
    Rectangle(double l = 0, double b = 0)
    {
        setLength(l);
        setBreadth(b);
    }
    void setLength(double);
    void setBreadth(double);
    double getLength(){return length;}
    double getBreadth(){return breadth;}
    double perimeter();
    double area();
    ~Rectangle(){};
};

class Cuboid:public Rectangle
{
    private:
    double height;
    public:
    Cuboid(double l = 0, double b = 0, double h = 0)
    {
        setLength(l);
        setBreadth(b);
        setHeight(h);
    }
    void setHeight(double);
    double SurfaceArea();
    double Volume();
    double getHeight(){return height;}
    ~Cuboid(){};
};

void Rectangle::setLength(double l)
{
    if(l > 0)
        length = l;
    else 
        length = 0;
}
void Rectangle::setBreadth(double b)
{
    if(b > 0)
        breadth = b;
    else 
        breadth = 0;
}
double Rectangle::perimeter()
{
    return 2*(length+breadth);
}
double Rectangle::area()
{
    return length*breadth;
}
void Cuboid::setHeight(double h)
{
    if(h > 0)
        height = h;
    else 
        height = 0;
}
double Cuboid::SurfaceArea()
{
    return 2*(getLength()*getBreadth()+getLength()*height+getLength()*height);
}
double Cuboid::Volume()
{
    return getLength()*getBreadth()*height;
}

int main()
{
    double inp1, inp2, inp3;
    cout<<"Enter the dimensions of a cuboid\n";
    cin>>inp1>>inp2>>inp3;

    Cuboid* c1 = new Cuboid(inp1, inp2, inp3);
    //Or, c1->setLength(inp1); c1->setBreadth(inp2); 
    //If, constructor was Cuboid(double);
    printf("Length = %lf units\t Breadth = %lf units\t Height = %lf units\t\n",c1->getLength(), c1->getBreadth(), c1->getHeight());
    cout<<"Volume of the cuboid is: "<<c1->Volume()<<" cubic units\n";
    cout<<"Surface area of the cuboid is: "<<c1->SurfaceArea()<<" square units\n";
    cout<<c1->area()<<" square units is the area of the cuboid's base\n";
    cout<<"Whereas, "<<c1->perimeter()<<" units is the base's perimeter\n";

    c1->~Cuboid();
    return 0;
}
