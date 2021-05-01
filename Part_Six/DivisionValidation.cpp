//To have a valid division operation
#include <iostream>
using namespace std;

int main()
{
	float a,b;
	cout<<"Enter two numbers\n";
	cin>>a>>b;
	
	if(a == 0 || b == 0)
	cout<<"Invalid input, cannot divide by zero \nPlease input non-zero values only"<<endl;
	else
	{
		cout<<a<<"/"<<b<<" = "<<a/b;
		cout<<"\n"<<b<<"/"<<a<<" = "<<b/a<<endl;
	}
	
	return 0;
}
