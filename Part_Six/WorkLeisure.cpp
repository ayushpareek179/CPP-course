//To check whether the input hourstamp can be classified as working hour
#include <iostream>
using namespace std;

void WorkLeisure(int a)
{
	if(a >= 9 && a <= 18)
	cout<<a<<" is a valid Working Hour input"<<endl;
	else
	cout<<"Save an hour like "<<a<<"th for leisure"<<endl;
	
	return;
}

int main()
{
	cout<<"Enter HH (hour) from HH:MM:SS\n";
	int hr; cin>>hr;
	
	if(hr < 0 || hr > 23)
	cout<<"Invalid input\nOught to lie between 0 and 23"<<endl;
	else
	WorkLeisure(hr);
	
	return 0; 
}
