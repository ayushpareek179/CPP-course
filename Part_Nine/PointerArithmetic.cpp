//To demonstrate pointer arithmetic
#include <iostream>
using namespace std;

void Initialize(int* ptr, int a)
{
    for(int i = 0; i < a; i++)
        cin>>*(ptr+i); //addition of integers
}

int* Display(int* ptr)
{
    int* p = ptr;
    while(*p != (int)NULL)
    {
        cout<<*p<<" ";
        p++; //incrementation
    }
    return p--;
}

int* RevDisplay(int* ptr, int* start)
{
    int* p = ptr;
    while(p >= start)
    {
        cout<<*p<<" ";
        p--; //decrmentation
    }
    return p++;
}

int main()
{
    cout<<"Enter a positive number\n";
    int n; cin>>n;

    if(n<0)
    {
        cout<<"Invalid input!";
        return 0;
    }

    int *p = new int[n];
    cout<<"Enter "<<n<<" numbers\n";
    Initialize(p,n);
    cout<<"You have entered\n";
    int* end = Display(p); //no need to pass the size!
    cout<<"\nYou probably recognize\n";
    int* start = RevDisplay(p+(n-1), p); 
    cout<<"\nSize of memory block: "<<(end-start-1)*sizeof(int)<<"\n"; //difference
    return 0;

}