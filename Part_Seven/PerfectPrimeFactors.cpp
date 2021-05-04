/*To print the factors of an input and check whether
    1. It's a perfect number
    2. It's a prime number
*/
#include <iostream>
using namespace std;
typedef long long ll;

ll factorSum(ll n, int key)
{
    ll sum = 1; //(n+1) if condition is altered
    int count = 1; //For isPrime(n, 0)
    
    if(key == 1) //For isPrime(n, 0)
    cout<<1<<", ";

    for(ll i = 2; i <= n/2; i++)
        if(n % i == 0)
        {
            if(key == 1)
            cout<<i<<", ";
            sum += i;
            
            ++count; //For isPrime(n, 0)
        }
    if(key == 1) //For isPrime(n, 0)
    {
        cout<<n;
        return sum;
    }

    if(n > 2)
    count += 1;
    return count;
}

bool isPerfect(ll n)
{
    ll temp = factorSum(n, 1);
    if (temp == n) //temp == 2*n
        return true;
    cout<<"\nSum of the factors of "<<n<<" = "<<temp+n;
    cout<<"\nHence "<<n<<" is not a perfect number";
    return false;
}

bool isPrime(ll n)
{
    if(factorSum(n,0) == 2)
        return true;
    return false;
}

int main()
{
    cout<<"Enter a positive number\n";
    ll num; cin>>num;

    if(num < 0)
    cout<<"Negative input!";
    else if(num == 0 || num == 1)
    cout<<num<<"\n"<<num<<" is a binary number";
    else
    {
        cout<<"Factors of "<<num<<" are:\n";
        if(isPerfect(num))
        {
            cout<<"\n"<<num<<" is a perfect number since the sum of";
            cout<<" its factors is equal to the number itself";
        }
        if(isPrime(num))
            cout<<"\n"<<num<<" has only two factors. Hence, it is a prime number";
        else
            cout<<"\n"<<num<<" has more than two factors. Hence, it's not a prime number";
    }
    return 0;
}