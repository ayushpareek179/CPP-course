//To depict a structure
#include <iostream>
#include <cmath>
using namespace std;

struct square //practically a class in CPP
{
    //everything is public by default
    double x;
    square(double x)
    {
        if(x > 0)
            this->x = x;
        else 
            this->x = -x;
    }
    //The functions (as written below) aren't permitted in C
    double area();
    double perimeter();
    double diagonal();
};
double square::area()
{
    return x*x;
}
double square::perimeter()
{
    return 4*x;
}
double square::diagonal()
{
    return sqrt(2)*x;
}

int main()
{
    cout<<"Enter the side of the square\n";
    double side; cin>>side;
    square *ptr = new square(side);

    cout<<"Area of square is: "<<ptr->area()<<"\n";
    cout<<"Perimeter of square is: "<<ptr->perimeter()<<"\n";
    cout<<"Diagonal of square is: "<<ptr->diagonal()<<"\n";

    return 0;
}