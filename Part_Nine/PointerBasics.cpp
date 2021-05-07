//To demonstrate what pointers are, and perform basic operations
#include <iostream>
using namespace std;

int main()
{
    cout<<"Enter a number\n";
    int n; cin>>n;

    int* p; //declaration
    p = &n; //initialization

    cout<<"The number you entered is:\n";
    cout<<n<<"\t//displayed using the variable\n";
    cout<<*p<<"\tdisplayed using dereferencing of pointer\n\n"; //dereferencing

    cout<<"The address at which your number was stored in the memory is:\n";
    cout<<&n<<"\t//displayed using ampersand operation on the variable your input was stored in\n";
    cout<<p<<"\t//displayed using the pointer\n\n";

    cout<<"The address of the pointer is:\n";
    cout<<&p<<"\t//displayed using ampersand on pointer\n";
    cout<<"(Address of the address)"<<endl;

    return 0;
}
