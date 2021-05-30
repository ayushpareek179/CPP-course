
#include <iostream>
#include <memory> //smart pointers
#include <cmath>
using namespace std;

class triangle
{
    private:
    double s1,s2,s3;
    public:
    triangle(double s1, double s2, double s3)
    {
        auto func = [](double i, double a)
        {
            if(i >= 0) 
            a = i; 
            else 
            a = 1;
        };
        func(s1, this->s1);
        func(s2, this->s2);
        func(s3, this->s3);
        if(!((s1+s2 >= s3)||(s1+s3 >= s2)||(s2+s3 >= s1)))
            this->s1 = this->s2 = this->s3 = 1;
        cout<<s1<<" "<<s2<<" "<<s3<<"\n";
    }
    double area()
    {
        double semi = (s1+s2+s3)/2;
        return sqrt(semi*(semi-s1)*(semi-s2)*(semi-s3));
    }
};

int main()
{
    unique_ptr<triangle> ptr(new triangle(3,4,5));
    cout<<"Area of triangle with sides 3, 4 and 5 is: "<<ptr->area()<<" square units\n";
    unique_ptr<triangle> p1;
    p1 = move(ptr);
    cout<<"Area of triangle with sides 3, 4 and 5 is: "<<ptr->area()<<" square units\n";
    return 0;
}