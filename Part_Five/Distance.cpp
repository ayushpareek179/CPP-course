//To find the distance covered, given the initial and final velocities and acceleration
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	float u, v, a, S = 0.0f;
	cout<<"Enter the initial and final velocities\n";
	cin>>u>>v;
	cout<<"Enter the acceleration experienced\n";
	cin>>a;
	S = (pow(v, 2) - pow(u, 2))/(2*a);
	cout<<"Distance covered by the body is "<<S<<" units"<<endl;
	return 0;
}
