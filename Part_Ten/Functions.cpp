/*To demonstrate functions using simple operations that include:
    1. Exponent function
    2. Addition of two inputs
    3. Maximum of three numbers
*/
#include <iostream>
using namespace std;

typedef long long ll;

double power(double a, ll b)
{
    if(a == 0 && b <= 0)
        return -1;
    
    double ans = 1;
    int flag = 0;
    if(b < 0)
    {
        flag = 1;
        b = -b;
    }
    
    for(int i = 1; i <= b; i++)
        ans *=a;
    
    if(flag == 1)
        ans = 1.0/ans;
    
    return ans;
}

double addition(double a, double b)
{
    return (a+b);
}

ll maximum(ll a, ll b, ll c)
{
    return (a>b)?((a>c)?a:c):((b>c)?b:c);
}

int main()
{
    cout<<"Menu:\n1. Raise a floating/integral base to an integral index\n";
    cout<<"2. Add two real numbers\n";
    cout<<"3. Find the maximum of three integers\n0. Do all of the above\n\n";

    while(true){
    cout<<"Enter your choice\n";
    int choice; cin>>choice;

    switch(choice)
    {
        case 0:
        case 1:
        {
            cout<<"Enter a floating/integral base and an integral index\n";
            double base; ll index; cin>>base>>index;

            cout<<base<<" raised to the power of "<<index<<" is:\n";
            double res = power(base,index);
            
            if(res == -1)
                cout<<"Undefined\n\n";
            else 
                cout<<res<<"\n\n";
            
            if(choice == 1)
                break;
        }
        case 2:
        {
            cout<<"Enter two real numbers\n";
            double a, b, e, d; cin>>a>>b;
            char c = '+'; int flag = 0;
            d = a; e = b;
            if(a < 0)
            {
                double temp = -a; a = b; b = temp;
                flag = 1;
                c = '-';
            }
            if(b < 0)
            {
                c = '-';
                b = -b;
            }
            if(flag == 1)
            {
                double temp = d;
                d = e; e = temp;
            }
            cout<<a<<" "<<c<<" "<<b<<" = "<<addition(d,e)<<"\n\n";
            if(choice == 2)
                break;
        }
        case 3:
        {
            cout<<"Enter three integers\n";
            ll a,b,c; cin>>a>>b>>c;
            cout<<"Maximum of three inputs is: "<<maximum(a,b,c);
            if(choice == 3 || choice == 0)
                break;
        }
        default:
            cout<<"Invalid input!";
    }
    cout<<"\n\nPress 'q' to quit\n"; 
    char ch; cin>>ch; 
    if(ch == 'q')
        break;
    else 
        cout<<"\n\n";
    }
    return 0;
}