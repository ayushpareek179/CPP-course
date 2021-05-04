//To output the first ten multiples of an input
#include <iostream>
using namespace std;

void TenMultiples(int num)
{
    for(int i=1; i<=10; i++)
    cout<<num<<" x "<<i<<" = "<<num*i<<"\n";
    return;
}

int main()
{
    cout<<"Enter a positive integer (for best aesthetics)\n";
    float a; cin>>a;
    TenMultiples((int)a);
    return 0;
}