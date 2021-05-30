//To demonstrate smart pointers
#include <iostream>
#include <memory> //smart pointers
#include <cmath>
using namespace std;

class triangle
{
    private:
    double s1,s2,s3;
    public:
    triangle(double j, double k, double l)
    {
        func(j, &s1); func(k, &s2); func(l, &s3);
        if(!((s1+s2 >= s3)||(s1+s3 >= s2)||(s2+s3 >= s1)))
            this->s1 = this->s2 = this->s3 = 1;
    }
    void func(double i, double* a)
    {
        if(i >= 0)
            *a = i; 
        else 
            *a = 1;
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
    p1 = move(ptr); //p1 = ptr; is unresponsive
    cout<<"Area of triangle with sides 3, 4 and 5 is: "<<p1->area()<<" square units\n"; //ptr->area() is meaningless

    shared_ptr<triangle> pt(new triangle(3,3,4));
    shared_ptr<triangle> p2(pt); //copy constructor
    //even p2 = pt; works 
    cout<<"Are of triangle with sides 3, 3 and 4 is: "<<pt->area()<<" "<<p2->area()<<"\n";
    cout<<"Reference count: "<<pt.use_count()<<"\n"; //or p2.use_count(), works same

    weak_ptr<triangle> pro = p2;
    auto p = pro.lock(); //auto p = pro makes p weak again
    cout<<"Are of triangle with sides 3, 3 and 4 is: "<<p->area()<<"\n"; //pro->area() doesn't work
    //weak pointers cannot be dereferenced directly
    pt.reset(); p2.reset(); //deletes
    //cout<<pt->area()<<"\n"; - program crashes
    cout<<"Reference count: "<<pro.use_count()<<"\n"; //displays 1 for weak and 2 for preexisting shared pointers (deleted later in previous line)
    //Thus, weak pointers aren't directly useful. These help in breaking shared pointer deadlocks

    return 0;
}