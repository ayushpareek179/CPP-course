//To show the difference between prefix and postfix operators
#include <iostream>
using namespace std;

int main()
{
	int x = 5, y = 10, z;
	int a = x, b = y, c;
	z = x++*y;
	c = ++a*b;
	cout<<"Pre-increment: "<<c<<"\nPost-increment: "<<z<<endl;
	return 0;
}
