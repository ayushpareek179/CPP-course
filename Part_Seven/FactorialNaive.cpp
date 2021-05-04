//To print factorial of a small number
#include <iostream>
using namespace std;
typedef long long ll;

ll factorial(ll a)
{
    if(a < 0)
    return -1;

    ll product = 1;
    for(int i = 1; i <= a; i++)
    product *= i;
    
    return product; 
}

int main()
{
    cout<<"Enter a small number, less than 21\nFor negative (invalid) inputs, -1 is displayed\n";
    ll num; cin>>num;
    
    cout<<num<<"! = "<<factorial(num);
    return 0;
}