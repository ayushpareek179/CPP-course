//To find the area of a circle
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double r, Area = 0.0d, pi = atan(1)*4;
	cout<<"Enter the radius of the circle\n";
	cin>>r;
	if(r<0)
	cout<<"Invalid input"<<endl;
	else
	{
		Area = pi*pow(r,2);
		cout<<"Area of the circle is "<<Area<<" units"<<endl;
	}
	return 0;
}
