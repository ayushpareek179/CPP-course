//To find the GCD of two inputs
#include <iostream>
#include <ctime>
using namespace std;
typedef long long ll;

ll GCD(ll a, ll b)
{
    ll temp;
    while(b % a != 0)
    {
        temp = a;
        a = b%a;
        b = temp;
    }
    return a;
}

ll HCF(ll x, ll y)
{
    while(x != y)
    {
        if(x > y)
            x = x - y;
        if(y > x)
            y = y - x;
    }
    return x;
}

int main()
{
    cout<<"Enter two non-negative integers\n";
    ll m, n; cin>>m>>n;
    
    if(m <= 0 || n <= 0)
        cout<<"Invalid input(s)!\n";
    else
    {
        time_t t = clock(); 
        cout<<"The GCD of "<<m<<" and "<<n<<" is: "<<GCD(m,n);
        t = clock() - t;
        cout<<"\nTime taken: "<<(double)t/CLOCKS_PER_SEC<<"\n";

        t = clock();
        cout<<"The HCF of "<<m<<" and "<<n<<" is: "<<HCF(m,n);
        t = clock() - t;
        cout<<"\nTime taken: "<<(double)t/CLOCKS_PER_SEC<<"\n";
    }
    return 0;
}