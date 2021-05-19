//To input and add rational numbers
//Student Exercise #10
#include <iostream>
using namespace std;

class Rational
{
    private:
    long p;
    long q;
    public:
    Rational(double p = 1, double q = 1)
    {
        setNum(p); 
        setDen(q);
    }
    void setNum(double p)
    {
        this->p = p;
    }
    void setDen(double q)
    {
        if(q <= 0)
        {
            if(q == 0)
                this->q = 1;
            else 
            {
                this->q = -q;
                p = -p;
            }
        }
        else 
            this->q = q;
    }
    Rational operator +(Rational);
    friend ostream& operator<<(ostream&, Rational);
    ~Rational(){};
};

long hcf(long a, long b)
{
    if(a < 0)
        a = -a;
    if(b < 0)
        b = -b;
    
    while(b % a != 0)
    {
        long temp = a;
        a = b%a;
        b = temp;
    }
    return a;
}
Rational Rational::operator+(Rational a)
{
    Rational temp;
    temp.p = p*a.q + a.p*q;
    temp.q = q*a.q;
    //to reduce to simplest fraction
    long h = hcf(temp.p, temp.q);
    while(h != 1)
    {
        temp.p /= h;
        temp.q /= h;
        h = hcf(temp.p, temp.q);
    }
    return temp;
}
ostream& operator<<(ostream& o, Rational r)
{
    o<<r.p<<"/"<<r.q;
    return o;
}

int main()
{
    cout<<"Enter a rational number\n";
    long p, q; cin>>p>>q;
    Rational A(p,q);

    cout<<"Enter another rational number\n";
    cin>>p>>q; Rational B(p,q);

    Rational C = A + B;
    cout<<"The sum of "<<A<<" and "<<B<<" is: "<<C<<"\n";

    return 0;
}