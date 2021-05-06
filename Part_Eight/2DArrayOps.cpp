/*To initialise 2D arrays and perform operations:
    1. Add and display the sum of inputs
    2. Subtract one input from the other, as per user's wish
    3. Multiply the unputs, as in matrix multiplication
    4. An average of all the elements
The results need to be displayed in a legible format*/
    
#include <iostream>
using namespace std;
typedef long long ll;

void GetDimensions(int* m, int* n)
{
    cout<<"\nEnter the array dimensions\n";
    cin>>*m>>*n;
    if(*m**n < 0)
    {
        cout<<"Invalid Input\n";
        return;
    }
}

void Initialize(ll* ar, int a, int b)
{
    //GetDimensions(a,b); - doesn't work here
    cout<<"\nEnter the elements\n";
    for(int i = 0; i < a; i++)
    {
        for(int j = 0; j < b; j++)
        {
            cin>>*(ar+i*b+j);
        }
    }
}

void Display(ll* ar, int x, int y)
{
    for(int i = 0; i < x; i++)
    {
        for(int j = 0; j < y; j++)
        {
            cout<<*(ar+i*y+j)<<" ";
        }
        cout<<"\n";
    }
}

void Average(ll *arr, int x, int y)
{
    ll sum = 0;
    for(int i = 0; i < x; i++)
    {
        for(int j = 0; j < y; j++)
        {
            sum += *(arr+i*y+j);
        }
    }
    cout<<"\nThe average of all the elements of the is: "<<(double)sum/(x*y)<<"\n";
}

void Addition(ll* first, ll* second, int x1, int y1, int x2, int y2)
{
    //Dimension checks
    if(x1 != x2 || y1 != y2)
    {
        cout<<"The two arrays are incompatible for addition\n";
        return;
    }
    ll sol[x1][y1];

    //Addition
    for(int i = 0; i < x1; i++)
    {
        for(int j = 0; j < y1; j++)
        {
            sol[i][j] = *(first+i*y1+j)+*(second+i*y1+j);
        }
    }
    cout<<"\nSum of the input matrices is:\n";
    Display(*sol,x1,y2);
}

void Subtraction(ll* first, ll* second, int x1, int y1, int x2, int y2)
{
    //Dimension checks
    if(x1 != x2 || y1 != y2)
    {
        cout<<"The two arrays are incompatible for subtraction\n";
        return;
    }
    
    ll sol[x1][y1];
    //Subtraction
    for(int i = 0; i < x1; i++)
    {
        for(int j = 0; j < y1; j++)
        {
            sol[i][j] = *(first+i*y1+j)-*(second+i*y1+j);
        }
    }
    Display(*sol,x1,y2);
}

void Multiplication(ll* first, ll *second, int x1, int y1, int x2, int y2)
{
    //Multiplication compatibility
    if(y1 != x2)
    {
        cout<<"The matrices are not compatible for multiplication\n";
        return;
    }
    //The solution matrix
    ll sol[x1][y2] = {0};
    //Display(*sol,x1,y2); - weird garbage values in row 0
    for(int i = 0; i < x1; i++)
    {
        for(int j = 0; j < y2; j++)
        {
            sol[i][j] = 0;
            for(int k = 0; k < x2; k++)
            {
                sol[i][j] += *(first+i*y1+k)**(second+k*y2+j);
            }
        }
    }
    cout<<"\nProduct of the input matrices is:\n";
    Display(*sol,x1,y2);
}

int main()
{
    //Initialization
    int x1, y1, x2, y2; 

    GetDimensions(&x1,&y1);
    ll A[x1][y1] = {0};
    Initialize(*A, x1, y1);
    
    GetDimensions(&x2,&y2);
    ll B[x2][y2] = {0};
    Initialize(*B, x2, y2);
    
    //Menu
    cout<<"\n\nOperate on the matrices:\nPress '0' for average of the matrix' elements\n";
    cout<<"Press '1' for addition\nPress '2' for subtracting first from second\n";
    cout<<"Press '3' for subtracting second from first\nPress '4' for multiplication\n";
    cout<<"Press '5' to do all of the above\n";
    int response; cin>>response;

    switch(response)
    {
        case 0:
        cout<<"\nFor the matrix\n";
        Display(*A, x1, y1);
        Average(*A, x1, y1);
        cout<<"\nFor the matrix\n";
        Display(*B, x2, y2);
        Average(*B, x2, y2);
        break;

        case 1:
        Addition(*A, *B, x1, y1, x2, y2);
        break;

        case 2:
        cout<<"\nSubtracting first matrix from the second:\n";
        Subtraction(*B, *A, x2, y2, x1, y1);
        break;
        
        case 3:
        cout<<"\nSubtracting second matrix from the first:\n";
        Subtraction(*A, *B, x1, y1, x2, y2);
        break;

        case 4:
        Multiplication(*A, *B, x1, y1, x2, y2);
        break;

        case 5:
        cout<<"\nFor the matrix\n";
        Display(*A, x1, y1);
        Average(*A, x1, y1);
        cout<<"\nFor the matrix\n";
        Display(*B, x2, y2);
        Average(*B, x2, y2);

        Addition(*A, *B, x1, y1, x2, y2);
        
        cout<<"\nSubtracting first matrix from the second:\n";
        Subtraction(*B, *A, x2, y2, x1, y1);
        
        cout<<"\nSubtracting second matrix from the first:\n";
        Subtraction(*A, *B, x1, y1, x2, y2);

        Multiplication(*A, *B, x1, y1, x2, y2);
        break;

        default: cout<<"Invalid entry!";
    }
    
    return 0;
}
/* A glimpse of returnable type and the clumsiness of functions
case 4:
        {
            ll C[x1][y1] = {0}; 
            if(Addition(*B, *A, *C, x2, y2, x1, y1, x1, y1))
            {
                cout<<"\nThe sum of input matrices is:\n";
                Display(*C, x1, y1);
            }

            cout<<"\n";

            if(Subtraction(*B, *A, *C, x2, y2, x1, y1, x1, y1))
            {
                cout<<"\nSubtracting first matrix from the second:\n";
                Display(*C, x1, y1);
            }
            cout<<"\n";

            if(Subtraction(*A, *B, *C, x1, y1, x2, y2, x1, y1))
            {
                cout<<"\nSubtracting second matrix from the first:\n";
                Display(*C, x1, y1);
            }
            break;
        }*/