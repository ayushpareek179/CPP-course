//Demonstrating bitwise operators 
#include <iostream>
using namespace std;

string DecBin(int n)
{
	string s = "", res = ""; int r, l = 0;
	while(n>0)
	{
		r = n%2;
		n = n/2;
		s = s+(char)(r+'0');
		l++;
	}
	r = s.length();
	l = 16 - l;
	for(int i = (r-1); i>=0; i--)
		res += s[i];
	if(l > 0)
	{
		for(int i = 1; i <= l; i++)
		res = "0"+res;
	}
	return res;
}

int main()
{
	int a, b, bit_and, bit_or, bit_xor, bit_comp, lshift, rshift;
	cout<<"Enter two natural numbers\n";
	cin>>a>>b;
	cout<<"For binary representation of inputs, press '1'\n";
	int x; cin>>x;
	if(x==1)
	{
		cout<<a<<" = "<<DecBin(a)<<"\n";
		cout<<b<<" = "<<DecBin(b)<<"\n";
	}
	
	bit_and = a & b; bit_xor = a ^ b;
	bit_or = a|b; bit_comp = ~a;
	lshift = a<<b; rshift = a>>b;
	
	cout<<a<<"&"<<b<<" = "<<bit_and<<"\n";
	cout<<a<<"|"<<b<<" = "<<bit_or<<"\n";
	cout<<a<<"^"<<b<<" = "<<bit_xor<<"\n";
	cout<<"~"<<a<<" = "<<bit_comp<<"\n";
	cout<<a<<"<<"<<b<<" = "<<lshift<<"\n";
	cout<<a<<">>"<<b<<" = "<<rshift<<endl;
	return 0;
}
