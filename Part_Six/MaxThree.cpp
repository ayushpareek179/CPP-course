//Maximum of three numbers
#include <iostream>
using namespace std;

int main()
{
	cout<<"Enter three numbers\n";
	float a, b, c, max; cin>>a>>b>>c;
	
	if(a>b && a>c)
	max = a;
	else if(b>c)
	max = b;
	else
	max = c;
	
	cout<<"The greatest of three is: "<<max<<endl;
	return 0; 
}
