//writing and reading files using C++
#include <fstream>
#include <iostream>
using namespace std;

void write()
{
    ofstream outfile("ProgFile.txt", ios::trunc);
    outfile<<"Numbers generated using a for loop:\n";
    for(int i = 0; i < 10; i++)
        outfile<<i<<" ";
    outfile<<"\nThe first attempt at writing to a file\n";
    outfile.close();
}

template<typename T>
void display(T* arr, int size, int* lineNo)
{
    cout<<"Line number "<<*lineNo<<":\t";
    *lineNo = *lineNo+1;
    for(int i = 0; i < size; i++)
        cout<<arr[i]<<" ";
    cout<<"\n";
}

void read()
{
    ifstream infile("ProgFile.txt");
    if(infile.is_open())
    {
        int countInstances = 0;
        int arr[10];
        string a[6], b[8];
        for(int i = 0; i <6; i++)
            infile>>a[i];
        
        for(int i = 0; i < 10; i++)
            infile>>*(arr+i);
        
        for(int i = 0; i<8; i++)
            infile>>b[i];

        cout<<"File contents:\n";
        display(a,6,&countInstances); 
        display(arr,10, &countInstances); 
        display(b,8, &countInstances);

        string s; infile>>s;
        if(infile.eof())
            cout<<"Reached the end of the file\n";
    }
    else 
        cout<<"File doesn't exist, cannot open it\n";
    infile.close();
}

int main()
{
    write();
    read();
    return 0;
}