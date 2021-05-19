//To demonstrate operator overloading using friend function for stream operators
#include <iostream>
#include <cmath>
using namespace std;

class Vector
{
    private:
    double iComp;
    double jComp;
    double kComp;
    public:
    Vector(double iComp = 0, double jComp = 0, double kComp = 0)
    {
        this->iComp = iComp;
        this->jComp = jComp;
        this->kComp = kComp;
    }
    void getComp()
    {
        cout<<iComp<<"i + ("<<jComp<<")j + ("<<kComp<<")k";
    }
    friend Vector operator +(Vector a, Vector b);
    friend istream& operator >>(istream&, Vector&);
    Vector operator -(Vector);
    Vector operator *(Vector);
    double dot(Vector);
    double magnitude();
    ~Vector(){};
};
Vector Vector::operator -(Vector x) //subtracts vectors
{
    Vector temp;
    temp.iComp = iComp - x.iComp;
    temp.jComp = jComp - x.jComp;
    temp.kComp = kComp - x.kComp;
    return temp;
}
istream& operator >>(istream& in, Vector& v) //sleeky results
{
    in>>v.iComp>>v.jComp>>v.kComp; //cin works too
    return in;
}
double Vector::dot(Vector q) //dot product of two vectors
{
    double dotProduct = iComp*q.iComp + jComp*q.jComp + kComp*q.kComp;
    return dotProduct;
}
Vector operator +(Vector a, Vector b) //adds two vectors
{
    Vector temp;
    temp.iComp = a.iComp + b.iComp; //can access without throwing error
    temp.jComp = a.jComp + b.jComp; //private data member accessible
    temp.kComp = a.kComp + b.kComp;
    return temp;
}
Vector Vector::operator *(Vector h) //cross product of two vectors
{
    Vector temp;
    temp.iComp = jComp*h.kComp - kComp*h.jComp;
    temp.jComp = iComp*h.kComp - kComp*h.iComp;
    temp.kComp = iComp*h.jComp - jComp*h.iComp;
    return temp;
}
double Vector::magnitude() //magnitude of a vector
{
    double mag = sqrt(iComp*iComp + jComp*jComp + kComp*kComp);
    return mag;
}
int main()
{
    Vector R, A, B;
    cout<<"Enter the components of first vector\n";
    cin>>A;

    cout<<"Enter the components of second vector\n";
    operator>>(cin,B); //works too

    R = operator+(A,B); //A+B works equally well
    cout<<"The resultant vector is: ";//R.iComp and other data members are inaccessible;
    R.getComp(); cout<<"\n";

    R = A - B;
    cout<<"The resultant vector is: "; R.getComp(); cout<<"\n";

    cout<<"Dot product of ";A.getComp();cout<<" and ";B.getComp();
    cout<<" is: "<<A.dot(B)<<"\n";

    R = A*B;
    cout<<"Cross product of ";A.getComp();cout<<" and ";B.getComp();
    cout<<" is: ";R.getComp();cout<<"\n";

    cout<<"Magnitude of ";A.getComp();cout<<" is: "<<A.magnitude()<<"\n";
    cout<<"Magnitude of ";B.getComp();cout<<" is: "<<B.magnitude()<<"\n";

    return 0;
}