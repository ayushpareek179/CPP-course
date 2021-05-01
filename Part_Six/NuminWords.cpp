//To display a number in words, in western system
//Help Resource https://www.geeksforgeeks.org/program-to-convert-a-given-number-to-words-set-2/

#include <iostream>
using namespace std;

string NumWord(int, string);
string LargeNumn(long long);

string LargeNum(long long num)
{
	string word = "";
	word += NumWord(num/1000000000, "billion");
	word += NumWord((num/1000000)%1000, "million");
	word += NumWord((num/1000)%1000, "thousand");
	word += NumWord(num%1000,"");
	return word;
}

string NumWord(int num, string appendage)
{
	string toReturn = "";
	string unique[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
					"ten","eleven", "twelve","thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
	string restens[] = {"", "","twenty","thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
	if(num < 100)
	{
		if(num<20)
		toReturn = unique[num];
		else
		toReturn = restens[num/10]+"-"+unique[num%10];
	}
	else
	{
		toReturn = unique[num/100]+" hundred ";
		num = num%100;
		if(num<20)
		toReturn += unique[num];
		else
		{
			if(num%10 != 0)
			toReturn += restens[num/10]+"-"+unique[num%10];
			else
			toReturn += restens[num/10];
		}
	}
	
	if(num != 0)
	toReturn += " "+appendage+" ";
	
	return toReturn;
}

int main()
{
	long long n;
	cout<<"Enter a number\n";
	cin>>n;
	
	if(n<0)
	cout<<"Minus "<<LargeNum(n);
	else
	cout<<LargeNum(n);
	
	return 0;	
}
