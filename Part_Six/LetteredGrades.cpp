//To award a grade as per the score obtained
#include <iostream>
using namespace std;

float input(float a, float b, float c)
{
	cout<<"Enter the scores for three subjects\n";
	cin>>a>>b>>c;
	if(a < 0 || a > 100) 
	cout<<"Invalid input for first score";
	else if(b < 0 || b > 100)
	cout<<"Invalid second score";
	else if(c < 0 || c > 100)
	cout<<"Invalid third score";
	else
	return (a+b+c)/3;
	
	return -1;
}

void AssignGrade(float a)
{
	cout<<"The remark and grade for this score are:\n";
	if(a > 85)
	cout<<"High Distinction: A";
	else if (a > 74)
	cout<<"Distinction: B";
	else if (a > 64)
	cout<<"Credit: C";
	else if (a > 49)
	cout<<"Pass: D";
	else
	cout<<"Failed: F";
	
	cout<<"\nTotal Score Obtained: "<<a*3<<endl;
	return;
}

int main()
{
	float a,b,c,grade;
	grade = input(a,b,c);
	if(grade == -1)
	cout<<""<<endl;
	else
	AssignGrade(grade);
	return 0;
}
