//An if..else program to output discount
#include <iostream>
using namespace std;

void Discount(float bill)
{
    float discount;
    
    if(bill < 100)
        discount = 0;
    else if(bill < 500)
        discount = 0.1*bill;
    else 
        discount = 0.2*bill;

    cout<<"For a billing amount of $"<<bill<<",\nDiscount availed = $"<<discount<<"\n";
    cout<<"Final amount charged = $"<<bill-discount;
    return;
}

int main()
{
    cout<<"Enter the bill amount\n";
    float bill; cin>>bill;

    if(bill < 0)
    cout<<"Invalid bill amount\n";
    else
    Discount(bill);

    return 0;
}