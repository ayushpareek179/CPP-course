//https://www.learncpp.com/cpp-tutorial/stdcin-and-handling-invalid-input/
//To show overflow on integers
#include <iostream>
using namespace std;
//std::numeric_limits<std::streamsize>::max()
template <typename T>
void inp(T* var)
{
	while(true)
	{
		cin>>*var;
		if(cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			cout<<"Invalid input type! Try again\n";
		}
		else 
		break;
	}
}
int main()
{
	int a, flag = 1;
	cout<<"Enter a number\n";
	inp(&a);
	cout<<"The number is: "<<a<<"\n";	
	return 0;
}
