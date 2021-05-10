/*To create a class rectangle and initialize objects 
and pointer to objects (in stack and heap)*/
#include <cmath>
#include <iostream>
using namespace std;
class Rectangle
{
    public:
    double length;
    double breadth;

    double area()
    {
        if(length <= 0 || breadth <= 0)
            return -1;
        return length*breadth;
    }

    double perimeter()
    {
        if(length <= 0 || breadth <= 0)
            return -1;
        return 2*(length+breadth);
    }

    double diagonal()
    {
        if(length <= 0 || breadth <= 0)
            return -1;
        return sqrt(length*length + breadth*breadth);
    }
};

int main()
{
    Rectangle r1, r2; //object in stack - 8 bytes
    Rectangle *ptr = &r2; //pointer to object in stack - 4 bytes pointer to 8-byte object
    Rectangle *heapPtr = new Rectangle(); //pointer to object in heap
    cout<<"Enter length and breadth for the first rectangle\n";
    cin>>r1.length>>r1.breadth;
    cout<<"\nEnter length and breadth for the second rectangle\n";
    cin>>ptr->length>>ptr->breadth;
    cout<<"\nEnter length and breadth for the third rectangle\n";
    cin>>heapPtr->length>>heapPtr->breadth;

    cout<<"Rectangle\t\tArea\t\tPerimeter\t\tDiagonal Length\n";
    cout<<"First\t\t\t"<<r1.area()<<"\t\t"<<r1.perimeter()<<"\t\t\t"<<r1.diagonal()<<"\n";
    cout<<"Second\t\t\t"<<r2.area()<<"\t\t"<<r2.perimeter()<<"\t\t\t"<<r2.diagonal()<<"\n";
    cout<<"Third\t\t\t"<<heapPtr->area()<<"\t\t"<<heapPtr->perimeter()<<"\t\t\t"<<heapPtr->diagonal()<<"\n";
    cout<<"\nNote: -1 indicates input parameter(s) were invalid";
    return 0;    
}
