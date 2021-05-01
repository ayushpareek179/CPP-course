//To calculate simple interest for a fixed sum, deposited at a fixed rate for a fixed time
#include <iostream>
using namespace std;

int main()
{
	float p, r, t, SI = 0.0;
	cout<<"Enter the principal, rate of interest and deposit-duration\n";
	cin>>p>>r>>t;
	if(p < 0 || r < 0 || t < 0)
	cout<<"Invalid input(s)";
	else
	{
		SI = p*r*t/100;
		cout<<"Simple interest accrued for "<<p<<" rupees at "<<r<<"% interest for "<<t<<" years is:\n"<<SI<<endl;
	}
	return 0;
}
