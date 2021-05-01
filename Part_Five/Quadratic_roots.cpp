//To calculate the roots of a quadratic equation
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	float a,b,c,x1,x2;
	x1 = x2 = 0.0f;
	cout<<"Enter the coeeficients a, b and c for the quadratic equation\n";
	cin>>a>>b>>c;
	float D = pow(b,2) - 4*a*c;
	if(D<0)
	cout<<"No natural roots"<<endl;
	else
	{
		x1 = (-b+sqrt(D))/(2*a);
		x2 = (-b-sqrt(D))/(2*a);
		cout<<"The roots are "<<x1<<" and "<<x2<<endl;
	}
	return 0;
}
