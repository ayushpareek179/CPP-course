//To demonstrate typedef and enum's working
#include <iostream>
using namespace std;
enum dept {IEE=6, Mech=12, Civil, Printing};
typedef int rollno;
typedef string name;

int main()
{
	dept d1 = IEE, d2 = Mech, d3 = Civil, d4 = Printing; //Can use statements like if(d1==Mech) et cetera
	
	cout<<"Enter four roll numbers"<<"\n";
	rollno a1, a2, a3, a4; //defining variables for dedicated usages
	cin>>a1>>a2>>a3>>a4;
	
	cout<<"Enter four names"<<"\n";
	name n1, n2, n3, n4;
	cin>>n1>>n2>>n3>>n4;
	
	cout<<"--------------------------------\n"<<"Name \t Roll Number \t Department\n";
	cout<<n1<<"\t\t"<<a1<<"\t\t"<<d1<<"\n";
	cout<<n2<<"\t\t"<<a2<<"\t\t"<<d2<<"\n";
	cout<<n3<<"\t\t"<<a3<<"\t\t"<<d3<<"\n";
	cout<<n4<<"\t\t"<<a4<<"\t\t"<<d4<<"\n";
	return 0;
}
