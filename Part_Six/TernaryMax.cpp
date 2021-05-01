//Demonstration of ternary operator to find max of four numbers
#include <iostream>
using namespace std;

int main()
{
	cout<<"Enter four integers\n";
	int a, b, c, d; 
	cin>>a>>b>>c>>d;
	int max = (a>b && a>c)?a:((b>c && b>d)?b:((c>d)?c:d));
	int Max = (a>b && a>c)?a:(b>c ? b:c);
	cout<<"Greatest of four: "<<max<<"\n";
	cout<<"Greatest of first three: "<<Max;
	return 0;
}
