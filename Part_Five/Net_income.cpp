//To calculate the net income based on an allowance and deduction percentage
#include <iostream>
using namespace std;

int main()
{
	float income, net, allowance_percent, deduction_percent;
	cout<<"Enter the basic salary, percentage of allowances and percentage of deductions\n";
	cin>>income>>allowance_percent>>deduction_percent;
	
	cout<<"For "<<allowance_percent<<"% allowances and "<<deduction_percent<<"% deductions on an income of $"<<income<<",\nNet income = $";
	net = income + income*allowance_percent/100 - income*deduction_percent/100;
	cout<<net<<endl;
	
	return 0;
}
