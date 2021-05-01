//To output a person's age category
#include <iostream>
using namespace std;

string AgeCategory(int a)
{
	if(a < 13)
	return "Child";
	else if(a < 19)
	return " Teenager";
	else if(a < 60)
	return "n Adult";
	else
	return " Senior Citizen";
}

int main()
{
	cout<<"Enter your age\n";
	int age; cin>>age;
	
	if(age<0)
	cout<<"Invalid input"<<endl;
	else
	cout<<"You're a"<<AgeCategory(age)<<endl;
	
	return 0;
}
