/*To search for a particular element in an array using
linear and binary search techniques and to compare the time elapsed*/
#include <iostream>
#include <ctime>
using namespace std;
typedef long long ll;

int LinSearch(ll a[], int n, int key)
{
    for(int i = 0; i < n; i++)
        if(a[i] == key)
            return i;
    
    return -1;
}

int BinSearch(ll a[], int n, int key)
{
    int l = 0, u = n-1, mid;
    while(l <= u) //if not for this condition, we're stuck in an infinite loop
    {
        int mid = (l+u)/2;
        if(a[mid] > key)
            u = mid - 1;
        if(a[mid] < key)
            l = mid+1;
        if(a[mid] == key)
            return mid;
    }
    return -1;
}

int main()
{
    cout<<"Enter the size of the array\n";
    int n; cin>>n;

    if(n <= 0)
    {
        cout<<"Invalid input!";
        return -1;
    }
    
    cout<<"Enter the elements\n";
    ll arr[n]; for(ll &x:arr) cin>>x;

    cout<<"\nEnter the key you intend to look for:\n";
    ll key; cin>>key;

    time_t t = clock();
    cout<<"Using linear search:\n";
    if(int index = LinSearch(arr,n,key); index >= 0)
        cout<<key<<" was found at "<<index<<"th position\nSearch was succesful";
    else 
        cout<<key<<" is not a part of the list of input numbers\nSearch was unsuccessful";
    t = clock() - t;
    printf("\nTime taken: %.5lf seconds\n",(double)t/CLOCKS_PER_SEC);

    t = clock();
    cout<<"Using binary search\n";
    if(int index = BinSearch(arr,n,key); index >= 0)
        cout<<key<<" was found at "<<index<<"th position\nSearch was succesful";
    else
        cout<<key<<" is not a part of the list of input numbers\nSearch was unsuccessful";
    t = clock() - t;
    printf("\nTime taken: %.5lf seconds\n",(double)t/CLOCKS_PER_SEC);

    return 0;
}