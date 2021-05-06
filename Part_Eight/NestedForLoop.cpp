//To demonstrate a nested for loop in a matrix format
#include <iostream>
using namespace std;

int main()
{
    cout<<"Below we see the working of a nested for loop\n";
    cout<<"\nfor(int i = 0; i <3; i++)\n";
    cout<<"{\n\tfor(int j = 0; j < 3; j++)\n";
    cout<<"\t\t{\n\t\t\tcout<<'('<<i<<','<<j<<') ';\n\t\t}\n\tcout<<endl;\n}\n\n\n";

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cout<<"("<<i<<","<<j<<") ";
        }
        cout<<"\n";
    }

    cout<<"\nPrinted using above syntax";
    return 0;
}