//To show various ways in which functions are called/parameters are passed
#include <iostream>
using namespace std;

void Swap(int* a, int *b) //call by address
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
//Becomes invalid when the function below is typed
/*void Swap(int a, int b) //does not swap - call by value
{
    int temp = a;
    a = b;
    b = temp;
    cout<<"Input #1: "<<a<<"\tInput #2: "<<b<<"\t//values switched inside the function\n";
}*/
void Swap(int &a, int &b) //call by reference - pasted machine code in main
{//inline function
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    cout<<"Enter two numbers\n";
    int x, y, *px = &x, *py = &y; cin>>x>>y;

    Swap(x,y); //pass by reference 
    cout<<"Input #1: "<<x<<"\tInput #2: "<<y<<"\t//values switched\n";
    
    /*swap(px, py); //pass by address
    cout<<"Input #1: "<<x<<"\tInput #2: "<<y<<"\t//values switched\n";*/

    Swap(&x, &y); //pass by address
    cout<<"Input #1: "<<x<<"\tInput #2: "<<y<<"\t//values switched back to original\n";

    return 0;
}