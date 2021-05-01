//To calculate the volume of a right-angled circular cylinder, given the radius and height
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	float r, h, pi = atan(1)*4, vol = 0.0f; 
	cout<<"Enter the radius and height of the cylinder\n";
	cin>>r>>h;
	if(r < 0 || h < 0)
	cout<<"Invalid input(s)"<<endl;
	else
	{
		vol = pi*pow(r,2)*h;
		cout<<"Volume of the cylinder is "<<vol<<" cubic units"<<endl;
	}
	return 0;
}
