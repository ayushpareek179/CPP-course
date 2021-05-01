//To show overflow on integers
#include <iostream>
using namespace std;

int main()
{
	int a = INT_MAX, b = INT_MIN;
	++a; --b;
	cout<<a<<" "<<b<<endl;
	return 0;
}
