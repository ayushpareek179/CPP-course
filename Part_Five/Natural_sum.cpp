//To calculate the sum of first n natural numbers
#include <iostream>
using namespace std;

int main()
{
	int n, sum = 0;
	cout<<"Enter n, until which the sum of natural numbers is desired"<<"\n";
	cin>>n;
	if(n<0)
	cout<<"Invalid input"<<endl;
	else
	{
		sum = n*(n+1)/2;
		cout<<"The sum of first "<<n<<" natural numbers is:\n"<<sum<<endl;
	}
	return 0;
}
