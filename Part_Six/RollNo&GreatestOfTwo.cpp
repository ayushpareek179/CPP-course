//To print the greater of two inputs and checking validity of a roll number
#include <iostream>
using namespace std;

void RollVal()
{
	cout<<"-----------------------\n";
	cout<<"Enter a roll number and the batch strength\n";
	int roll, batch; cin>>roll>>batch;
	
	if(roll <= 0)
	cout<<"Invalid input\nA roll ought not to be non-positive"<<endl;
	else if(batch <= 0)
	cout<<"Invalid input\nA Batch size ought not to be non-positive";
	else if(roll > batch)
	cout<<"Invalid input\nThere aren't this many students in the class\n"<<roll<<"th student out of "<<batch<<" students not possible"<<endl;
	else
	cout<<roll<<" is a valid roll number\nBatch size is "<<batch<<endl;
	
	return;
}

void GTwo()
{
	cout<<"-------------------------\n";
	cout<<"Enter two integers\n";
	int n1, n2; cin>>n1>>n2;
	
	if(n1 == n2)
	cout<<"Identical input twice"<<endl;
	else
	cout<<(n1>n2?n1:n2)<<" is the greater of two inputs"<<endl;
	
	return;
}

int main()
{
	cout<<"For verifying roll number, press 1\nFor determining the greater of two inputs, press 2\nFor both, press 3\n";
	int n; cin>>n;
	
	if(n==1)
	RollVal();
	else if(n==2)
	GTwo();
	else if(n==3)
	{
		RollVal();
		GTwo();
	}
	else
	cout<<"Invalid input";
	
	return 0;
}
