//To implement encapsulation in classes
#include <iostream>
#include <cmath>
using namespace std;

class Rectangle
{
    private:
    float length;
    float breadth;
    public:
    void setLength(float l) //equipped to handle a negative input
    {
        length = l;
        if(length <= 0)
            length = -l;
    }
    void setBreadth(float b) //equipped to handle a negative input
    {
        breadth = b;
        if(breadth <= 0)
            breadth = -b;
    }
    float getLength()
    {
        return length;
    }
    float getBreadth()
    {
        return breadth;
    }
    float area()
    {
        return length*breadth;
    }
    float perimeter()
    {
        return 2*(length+breadth);
    }
    float diagonal()
    {
        return sqrt(length*length + breadth*breadth);
    }
};

int main()
{
    Rectangle *ptr = new Rectangle();

    cout<<"Enter the length and breadth of rectangle\n";
    float x, y; cin>>x>>y;
    ptr->setLength(x); ptr->setBreadth(y);
    
    cout<<"Length of rectangle is: "<<ptr->getLength()<<"\n";
    cout<<"Breadth of rectangle is: "<<ptr->getBreadth()<<"\n";
    cout<<"Area of rectangle is: "<<ptr->area()<<"\n";
    cout<<"Perimeter of rectangle is: "<<ptr->perimeter()<<"\n";
    cout<<"Diagonal of rectangle is: "<<ptr->diagonal();

    return 0;
}