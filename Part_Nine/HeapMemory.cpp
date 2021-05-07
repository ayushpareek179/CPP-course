//To depict use of heap memory using pointers
#include <iostream>
using namespace std;

int main()
{
    cout<<"Enter a small positive number\n";
    int size; cin>>size;
    int* p = new int[size];

    cout<<"Current size of memory allocated in heap = "<<sizeof(p)<<"\n";
    cout<<"Enter another positive number\n";
    cin>>size;
    cout<<"Deleting memory allocated earlier\n";
    delete []p;
    cout<<"Reallocating..\n";
    p = new int[size];
    cout<<"New memory block size = "<<sizeof p<<"\n";
    delete []p;
    cout<<"Deleting new memory block\n";
    p = nullptr;
    cout<<"Misleading?!\nVisit this link to understand why we're never shown how much dynamic memory was allocated\n";
    cout<<"https://stackoverflow.com/questions/26411637/c-size-of-dynamic-memory-at-runtime#:~:text=Note%20that%20the%20C%2B%2B%20standard,so%20that%20the%20memory%20is";
    return 0;
}