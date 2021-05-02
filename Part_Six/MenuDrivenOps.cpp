//To perform an operation based upon user input
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int option;
    cout<<"Menu\n1. Exponent\n2. Multiplication\n3. Addition\n";
    cout<<"Choose option by pressing the number\n";
    cin>>option;

    float a,b;
    cout<<"Enter two numbers\n";
    cin>>a>>b;

    switch(option)
    {
        case 1:cout<<"To treat "<<b<<" as index, press 'a' ";
        cout<<"Otherwise, press 'b'\n";
        char c; cin>>c;
        
        switch(c)
        {
            case 'a':cout<<a<<" raised to the power of "<<b<<" = "<<pow(a,b);
            break;
            case 'b':cout<<b<<" raised to the power of "<<a<<" = "<<pow(b,a);
            break;
            default:cout<<"Invalid input!";
        }
        break;

        case 2:cout<<"To print the product of "<<a<<" and "<<b<<" press 'a'";
        cout<<"\nFor division, press 'b'\n";
        char in; cin>>in;

        switch(in)
        {
            case 'a':cout<<a<<"*"<<b<<" = "<<a*b;
            break;

            case 'b':
            if(a*b == 0)
            {
                if(a == 0 && b!= 0)
                cout<<a<<"/"<<b<<" = "<<0<<"\nCannot divide by first input";
                else if(b == 0 && a != 0)
                cout<<b<<"/"<<a<<" = "<<0<<"\nCannot divide by second input";
                else
                cout<<"Invalid inputs for division\nCannot divide by zero";
            }
            else
            cout<<a<<"/"<<b<<" = "<<a/b<<"\n"<<b<<"/"<<a<<" = "<<b/a;
            break;

            default:cout<<"Invalid input!";
        }
        break;

        case 3:cout<<"For addition, press '+'\nTo subtract, press '-'\n";
        char op; cin>>op;

        switch(op)
        {
            case '+':cout<<a<<"+"<<b<<" = "<<a+b;
            break;
            case '-':cout<<a<<"-"<<b<<" = "<<a-b<<"\n"<<b<<"-"<<a<<" = "<<b-a;
            break;
            default:cout<<"Invalid input!";
        }
        break;

        default:cout<<"Invalid input!";
    }
    
    cout<<"\nExit"<<endl;
    return 0;
}