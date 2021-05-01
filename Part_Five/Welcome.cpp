#include <iostream>
int main()
{
	std::string s;
	std::cout<<"May I know your name?"<<"\n";
	getline(std::cin, s);
	std::cout<<"Welcome "<<s<<"!\n";
	return 0;
}
