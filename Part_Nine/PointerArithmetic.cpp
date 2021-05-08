//To demonstrate pointer arithmetic
#include <iostream>
using namespace std;

void Initialize(int* ptr, int a)
{
    for(int i = 0; i < a; i++)
        cin>>*(ptr+i); //addition of integers
}

int* Display(int* ptr, int n)
{
    int* p = ptr;
    while(p != ptr+n)
    {
        cout<<*p<<" ";
        p++; //incrementation
    }
    p--;
    return p;
}

int* RevDisplay(int* ptr, int* start)
{
    int* p = ptr;
    while(p >= start)
    {
        cout<<*p<<" ";
        p--; //decrmentation
    }
    p++;
    return p;
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
    int* end = Display(p,n);
    cout<<"\nYou probably recognize\n";
    int* start = RevDisplay(p+(n-1), p); 
    //cout<<"\n"<<*start<<" "<<*end<<"\n";
    //Enabled correction of last incrementation/decrementation in respective return statements
    cout<<"\nSize of memory block: "<<(end-start+1)*sizeof(int)<<"\n"; //difference
    delete []p;
    p = nullptr;
    return 0;

}