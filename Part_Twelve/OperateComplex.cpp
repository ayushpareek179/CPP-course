//To demonstrate operator overloading
#include <iostream>
#include <cmath>
using namespace std;

template <typename T>
T absolute(T num)
{
    if(num < 0)
        return -num;
    return num;
}
class Complex
{
    private:
    double real;
    double imaginary;
    public:
    Complex(double x = 0, double y = 0)
    {
        real = x;
        imaginary = y;
    }
    Complex operator +(Complex);
    Complex operator -(Complex);
    Complex operator *(Complex);
    Complex operator /(Complex);
    double mod();
    double getreal(){ return real;}
    double getimg(){return imaginary;}
    void printer(int);
    //Complex operator *(Complex);
    ~Complex(){};
};

int main()
{
    Complex c3;
    cout<<"Enter real and imaginary parts of the first complex number\n";
    double x, y; cin>>x>>y; Complex c1(x,y);
    cout<<"Enter real and imaginary parts of the second complex number\n";
    cin>>x>>y; Complex c2(x,y);
    
    c3 = c1 + c2;
    c1.printer(1);cout<<" + ";c2.printer(1);cout<<" = ";c3.printer(0);
    cout<<"\n";
    
    c3 = c1 - c2;
    c1.printer(1);cout<<" - ";c2.printer(1);cout<<" = ";c3.printer(0);
    cout<<"\n";
    
    c3 = c1*c2;
    c1.printer(1);cout<<" * ";c2.printer(1);cout<<" = ";c3.printer(0);
    cout<<"\n";

    c3 = c1/c2;
    c1.printer(1);cout<<" / ";c2.printer(1);cout<<" = ";c3.printer(0);
    cout<<"\n";

    cout<<"arg";c1.printer(1);cout<<" = "<<c1.mod()<<"\n";
    cout<<"arg";c2.printer(1);cout<<" = "<<c2.mod()<<"\n";
    
    return 0;
}

Complex Complex::operator -(Complex a)
{
    Complex temp;
    temp.real = real - a.real;
    temp.imaginary = imaginary - a.imaginary;
    return temp;
}
Complex Complex::operator +(Complex x)
{
    Complex temp;
    temp.real = x.real + real;
    temp.imaginary = x.imaginary + imaginary;
    return temp;
}
void Complex::printer(int a)
{
    int flag = 1;
    if(imaginary < 0)
        flag = 0;
    if(a == 0) //no parentheses
    {
        if(flag) //non-negative imaginary component
        {
            if(real == 0 && imaginary == 0)
                cout<<"0";
            else if(real != 0 && imaginary == 1)
                cout<<real<<" + i";
            else if(imaginary == 0)
                cout<<real;
            else if(real == 0 && imaginary == 1)
                cout<<"i";
            else if(real == 0 && imaginary != 1)
                cout<<imaginary<<"i";
            else
                cout<<real<<" + "<<imaginary<<"i";
        }
        else
        {
            if(real == 0 && imaginary == -1)
                cout<<" -i";
            else if(real == 0 && imaginary != -1)
                cout<<" - "<<absolute(imaginary)<<"i";
            else if(real != 0 && imaginary == -1)
                cout<<real<<" - i";
            else 
                cout<<real<<" - "<<absolute(imaginary)<<"i";
        }
    }
    else if(a == 1) 
    {
        if(flag) //non-negative imaginary component
        {
            if(real == 0 && imaginary == 0)
                cout<<"0";
            else if(real != 0 && imaginary == 1)
                cout<<"("<<real<<" + i)";
            else if(imaginary == 0)
                cout<<"("<<real<<")";
            else if(real == 0 && imaginary == 1)
                cout<<"i";
            else if(real == 0 && imaginary != 1)
                cout<<"("<<imaginary<<"i)";
            else
                cout<<"("<<real<<" + "<<imaginary<<"i)";
        }
        else
        {
            if(real == 0 && imaginary == -1)
                cout<<" - i";
            else if(real == 0 && imaginary != -1)
                cout<<"( - "<<absolute(imaginary)<<"i)";
            else if(real != 0 && imaginary == -1)
                cout<<"("<<real<<" - i)";
            else 
                cout<<"("<<real<<" - "<<absolute(imaginary)<<"i)";
        }
    } 
}
Complex Complex::operator *(Complex n)
{
    Complex temp;
    temp.real = real*n.real - imaginary*n.imaginary;
    temp.imaginary = real*n.imaginary + imaginary*n.real;
    return temp;
}
Complex Complex::operator /(Complex t)
{
    if(t.real == 0 && t.imaginary == 0)
        return 0;
    double img2 = - t.imaginary;
    Complex temp1(t.real, img2);
    Complex den = t*temp1;
    Complex num = *this*temp1; //using the current object
    Complex temp;
    temp.real = num.real/den.real;
    temp.imaginary = num.imaginary/den.real;
    return temp;
}
double Complex::mod()
{
    return sqrt(real*real + imaginary*imaginary);
}
