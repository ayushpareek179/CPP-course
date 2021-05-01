//To return the month name for a numeric input
#include <iostream>
using namespace std;

string month(int n)
{
	string m[] = {"December", "January", "February", "March", "April", "May", "June", "July", "August",
					"September", "October", "November"};
	n = n%12;
	return m[n];
}

int main()
{
	int num; 
	cout<<"Enter a (month) number\n";
	cin>>num;
	
	if(num > 12 || num <1)
	cout<<"Invalid input";
	else
	cout<<"The "<<num<<"th month is "<<month(num);
	
	cout<<endl;
	return 0;
}
