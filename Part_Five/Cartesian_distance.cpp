//To compute distance between two points in cartesian coordinate system
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	float x1, x2, y1, y2, distance = 0.0f;
	cout<<"Enter the cartesian coordinates (x,y) of the two points\n";
	cin>>x1>>y1>>x2>>y2;
	distance = sqrt(pow(x1-x2,2)+pow(y1-y2,2));
	cout<<"The distance between ("<<x1<<","<<y1<<") and ("<<x2<<","<<y2<<") is:\n"<<distance<<" units"<<endl;
	return 0;
}
