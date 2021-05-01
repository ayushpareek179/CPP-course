//To return day of the week as per day-number
#include <iostream>
using namespace std;
typedef int day; 

string DayName(day d)
{
	if(d == 1)
	return "Monday";
	else if(d == 2)
	return "Tuesday";
	else if(d == 3)
	return "Wednesday";
	else if(d == 4)
	return "Thursday";
	else if(d == 5)
	return "Friday";
	else if(d == 6)
	return "Saturday";
	else
	return "Sunday";
}

int main()
{
	day n;
	cout<<"Enter a (day) number between 1 and 7\n";
	cin>>n;
	
	if(n < 1 || n > 7)
	cout<<"Invalid day-input";
	else
	cout<<"Week's "<<n<<"th day is "<<DayName(n)<<endl;
	
	return 0;
}
