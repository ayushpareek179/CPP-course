//To calculate the area of a triangle, with base and height as inputs
#include <iostream>
using namespace std;

int main()
{
	cout<<"Enter the base and height"<<"\n";
	float base, height;
	cin>>base>>height;
	if(base <= 0 || height <= 0)
	cout<<"Invalid input!"<<endl;
	else
	{
		float area = base*height/2;
		cout<<"Area of the triangle is "<<area<<" units"<<endl;
	}
	return 0;
}
