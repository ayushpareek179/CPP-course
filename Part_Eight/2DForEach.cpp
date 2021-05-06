//To demonstrate the use of for each loop on 2D arrays
#include <iostream>
using namespace std;

int main()
{
    cout<<"Enter array dimensions\n";
    int x, y; cin>>x>>y;

    if(x*y < 0)
    {
        cout<<"Invalid input(s)!";
        return -1;
    }

    cout<<"Enter the array elements\n";
    int arr[x][y];
    for(auto& x:arr) //the only option: takes one row as input at a time
    {
        for(int& y:x) //interchangeable with auto&
        {
            cin>>y;
        }
    }

    cout<<"The elements of the array are:\n";
    for(auto& x:arr)
    {
        for(int& y:x)
        {
            cout<<y<<" ";
        }
        cout<<endl;
    }

    return 0;
}