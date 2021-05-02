//To output name of the day using switch case
#include <iostream>
using namespace std;

int main()
{
    int n; 
    cout<<"Enter a day number\n";
    cin>>n;

    if(n>0 && n<8)
    cout<<"The "<<n<<"th day of the week is ";
    switch(n)
    {
        case 1: cout<<"Monday";
        break;

        case 2: cout<<"Tuesday";
        break;

        case 3: cout<<"Wednesday";
        break;

        case 4: cout<<"Thursday";
        break;

        case 5: cout<<"Friday";
        break;

        case 6: cout<<"Saturday";
        break;

        case 7: cout<<"Sunday";
        break;

        default:
        cout<<n<<" is not a valid input\nEnter a number between 1 and 7";
    }

    return 0;
}