//To demonstrate the three loop structures
#include <iostream>
#include <cmath>
using namespace std;

int SumOfDigits(int a)
{
    int d = 0;
    while(a != 0)
    {
        d = d + a%10;
        a = a/10;
    }
    return d;
}

int ProductOfDigits(int n)
{
    int p = 1, div;
    for(int i = 0; ; i++)
    {
        div = n/(int)pow(10,i);
        if(div == 0)
        break;
        p = p*(div%10);
    }
    return p;
}

int main()
{
    int q;
    do{
        q = 0;
        cout<<"\nEnter a number\n";
        int num,n; cin>>num;

        cout<<"\nSum of digits of "<<num<<" is: "<<SumOfDigits(num);
        cout<<"\nProduct of digits of "<<num<<" is: "<<ProductOfDigits(num);

        cout<<"\nPress '1' to continue\n";
        cin>>q;
    }while(q == 1);

    return 0;
}