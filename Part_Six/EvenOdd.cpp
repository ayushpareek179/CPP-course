//To check if the input is even
#include <iostream>
using namespace std;

int main()
{
	cout<<"Enter a number\n";
	int num; cin>>num;
	
	if(num%2==0)
	cout<<num<<" is an even number"<<endl;
	else
	cout<<num<<" is an odd number"<<endl;
	
	return 0;
}
