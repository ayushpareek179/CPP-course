//To demonstrate refrences' baiscs
#include <iostream>
using namespace std;

void change(int* a) //References are akin to pointers
{
    *a = *a**a;
}

int main()
{
    cout<<"Enter a number\n";
    int n, k; cin>>n; 
    k = n; //k's value doen't change at all, since it's not a reference
    int *ptr = &n; int &r = n;
    
    change(&n); //Changes the value held within
    cout<<k<<" raised to the power 2: "<<n<<"\n";
    //ptr = &k - allowed
    change(ptr); //Changes again
    cout<<k<<" raised to the power 4: "<<n<<"\n";
    //&r = k - not allowed
    //r = k - changes the value stored within
    change(&r); //Changes once again - proves reference and the variable it's assigned with share their addresses
    cout<<k<<" raised to the power 8: "<<n<<"\n";

    return 0;
}