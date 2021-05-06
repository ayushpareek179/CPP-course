/*To read an array and display:
    1. The sum of its elements
    2. The maximum element held in it
    3. The minimum element held in it
    4. The number of positive and negative elements
*/
#include <iostream>
using namespace std;
typedef long long ll;

ll ArraySum(ll a[], int n)
{
    ll sum = 0;
    for(int i=0; i<n; i++)
        sum += a[i];
    return sum;
}

ll MaxElement(ll a[], int n)
{
    ll max = a[0];
    for(int i = 0; i < n; i++)
        if(a[i] > max)
            max = a[i];
    
    return max;
}

ll MinElement(ll a[], int n)
{
    ll min = a[0];
    for(int i = 0; i < n; i++)
        if(a[i] < min)
            min = a[i];
    
    return min;
}

ll* CountNegPos(ll a[], int n)
{
    static ll arr[3] = {0};
    for(int i=0; i<n; i++)
        if(a[i] > 0)
            arr[1]++;
        else if(a[i] < 0)
            arr[2]++;
        else 
            arr[0]++;
    
    return arr;
}

int main()
{
    cout<<"Enter the size of array\n";
    int size; cin>>size;

    if(size <=0)
    cout<<"Invalid input\n";
    else
    {
        cout<<"Enter the array elements\n";
        ll arr[size];
        for(ll &x:arr) //Found a new method to feed values!
            cin>>x;
        
        cout<<"Sum of the elements of the array is: "<<ArraySum(arr, size)<<"\n";
        cout<<"Largest element in the array is: "<<MaxElement(arr, size)<<"\n";
        cout<<"Smallest element of the array is: "<<MinElement(arr, size)<<"\n";
        ll* PN = CountNegPos(arr,size);
        cout<<"Number of positive elements: "<<*(PN+1)<<"\n";
        cout<<"Number of negative elements: "<<*(PN+2)<<"\n";
        cout<<"Number of zeroes: "<<*PN<<"\n"; 
    }
    return 0;
}