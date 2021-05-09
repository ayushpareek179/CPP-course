/*To demonstrate scope, scope resolution operator and 
various accessibility levels for variables using simple code*/
#include <iostream>
using namespace std;

char ch = 'g'; //global declaration

void Change()
{
    ch--; //global variable
    cout<<"ch = "<<ch<<"\n";
}

void NoChange()
{
    char ch = 'j'; //Not the global one
    ch++; cout<<"ch = "<<ch<<"\n";
    {
        char ch = 'y'; //Not the one decalred outside
        cout<<"ch = "<<ch <<"\n";
    }
    ::ch -= 3; //scope resolution for bringing in global variable
    cout<<"ch = "<<::ch <<"\n";
}

int main()
{
    ch += 10; //global
    cout<<"ch = "<<ch<<"\n";
    NoChange(); //one change in global ch
    Change(); //self-explanatory name
    return 0;
}