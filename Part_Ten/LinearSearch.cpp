//To pass an array and search for a key
//Course Assignment
#include <iostream>
using namespace std;

int LinearSearch(int* arr, int key, int size)
{
    for(int i = 0; i < size; i++)
        if(*(arr+i) == key)
            return i;
    return -1;
}

int main()
{
    cout<<"Enter the array size\n";
    int s; cin>>s;
    if(s <= 0)
    {
        cout<<"Invalid input! Size ought to be positive\n";
        return -1;
    }
 
    cout<<"Enter the array elements\n";
    int A[s]; 
    for(int i = 0; i < s; i++)
        cin>>*(A+i);
    
    cout<<"Enter the elemnt to be searched\n";
    int k; cin>>k;

    int index = LinearSearch(A, k, s);
    if(index == -1)
        cout<<"Element not found\n";
    else 
        cout<<"Found at index "<<index<<"\n";
    
    return 0;
}