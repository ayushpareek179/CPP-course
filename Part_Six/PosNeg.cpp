//To check whether the input is a positive number
#include <iostream>
using namespace std;

void PosNeg(int a)
{
	if(a > 0)
	cout<<a<<" is a positive integer"<<endl;
	else
	cout<<a<<" is a negative integer"<<endl;
	return;
}

int main()
{
	cout<<"Enter an integer\n";
	int num; cin>>num;
	
	if(num == 0)
	cout<<num<<" is neither positive nor negative"<<endl;
	else
	PosNeg(num);
	
	return 0;
}
