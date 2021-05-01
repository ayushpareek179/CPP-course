//To output a quadratic equation's roots and their nature
#include <iostream>
#include <cmath>
using namespace std;

void Complex(float x2, float x1, float x0, float Di)
{
	cout<<"The equation has no real roots\n";
	float real = -x1/(2*x2);
	float imaginary = sqrt(-Di)/(2*x2);
	cout<<"The solutions are \nx = "<<real<<" + "<<imaginary<<"i\nand x = "<<real<<" - "<<imaginary<<"i\n";
	cout<<"'i' is the square root of -1";
}

void Real(float x2, float x1, float x0, float Di)
{
	float r1 = (-x1+sqrt(Di))/(2*x2);
	float r2 = (-x1-sqrt(Di))/(2*x2);
	if(Di == 0)
	{
		cout<<"The equation has real and equal roots\n";
		cout<<"The solution is x = "<<r1;
	}
	else
	{
		cout<<"The equation has real and unequal roots\n";
		cout<<"The solutions are x = "<<r1<<" and x = "<<r2;
	}
	return;
}

int main()
{
	float a, b, c, D;
	cout<<"Enter the coefficients of quadratic equation\n";
	cout<<"ax^2 + bx + c = 0\n";
	cin>>a>>b>>c;
	
	D = pow(b,2) - 4*a*c;
	if(D<0)
	Complex(a,b,c,D);
	else
	Real(a,b,c,D);
	cout<<endl;
	
	return 0;
}
