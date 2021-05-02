//To demonstrate short-circuiting in action
#include <iostream>
using namespace std;

void andSC(int x, int y, int z)
{
	cout<<"-----------------------\n";
	printf("x = %d, y = %d, z = %d\n",x,y,z);
	
	cout<<"if(x<y && ++y<z)\n";
	cout<<"Here, outputting y shows the effect of short-circuiting\n";
	if(x<y && ++y<z){}
	cout<<"y = "<<y<<"\n-----------------------\n";
	
	cout<<"if(x>y && ++y<z)\n";
	cout<<"Here, outputting y shows the alternate reality\n";
	if(x>y && ++y<z){}
	cout<<"y = "<<y;
	
	return;
}

void orSC(int x, int y, int z)
{
	cout<<"-----------------------\n";
	printf("x = %d, y = %d, z = %d\n",x,y,z);
	
	cout<<"if(x>y || ++y<z)\n";
	cout<<"Here, outputting y shows the effect of short-circuiting\n";
	if(x>y || ++y<z){}
	cout<<"y = "<<y<<"\n-----------------------\n";
	
	cout<<"if(x<y || ++y<z)\n";
	cout<<"Here, outputting y shows the alternate reality\n";
	if(x<y || ++y<z){}
	cout<<"y = "<<y;
	
	return;
}

int main()
{
	cout<<"Enter 1 for &&\nEnter 2 for ||\nEnter 3 for both\n";
	int a = 10, b = 5, c = 5, choice; cin>>choice;
	
	if(choice > 3 || choice < 0)
	cout<<"Invalid input!\nEnter a number between 1 and 3\n";
	else if(choice == 1)
	andSC(a,b,c);
	else if(choice == 2)
	orSC(a,b,c);
	else
	{
		andSC(a,b,c);
		cout<<"\n";
		orSC(a,b,c);
	}
	
	return 0;
}
