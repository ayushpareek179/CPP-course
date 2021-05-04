//To demonstrate an infinite loop
#include <iostream>
using namespace std;

int main()
{
    cout<<"The loop runs indefinitely long\n";
    int i = 0;
    do{
        cout<<"Iteration "<<i<<"\n";
        i++;

        //if(i == 10) break;
    }while(1); //always true
    return 0;
}