//To draw patterns using nested for loops
#include <iostream>
#include <cmath>
using namespace std;

int digits(int m) //Helper function for general padding
{
    int count = 0;
    while(m != 0)
    {
        m = m/10;
        count++;
    }
    return count;
}

void SumRectangle(int n)
{
    int sum = 0, max = n*n, sumDig;
    int maxDig = digits(max);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            sum++; sumDig = digits(sum);
            cout<<sum;
            //Padding for aesthetics
            for(int a = sumDig; a <= maxDig; a++)
                cout<<" ";
        }
        cout<<"\n";
    }
}

void LowerTriangle(int n)
{
    //int sum = 0; - Padding not needed since all asterisks are
    //equally dimensioned relatively
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i >= j)
                cout<<"*  ";
        }
        cout<<"\n";
    }
}

void UpperTriangle(int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(j >= i)
                cout<<"*  ";
            //To prevent confusion with j <= (jMax - i)
            else
                cout<<"   ";    
        }
        cout<<"\n";
    }
}

void RightInvertLow(int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(j >= (n-1-i))
            //similar to saying: "(i+j) > (n-1)"
                cout<<"*  ";
            else
                cout<<"   ";
        }
        cout<<"\n";
    }
}

void RightInvertUp(int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i+j < n)
                cout<<"*  ";
            //else block is redundant
        }
        cout<<"\n";
    }
}

int absolute(int n) //Helper function for figure-combinations
{
    if(n < 0)
        return -n;
    return n;
}

void InvertedTriangle(int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 2*n-1; j++)
        {
            //The inverted entities need a i-j combine
            //on the same side of equation
            if(i+absolute(j-(n-1)) < n)
                cout<<"*  ";
            else 
                cout<<"   ";
        }
        cout<<"\n";
    }
}

void Triangle(int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 2*n-1; j++)
        {
            //The non-inverted entities require i-j on either
            //sides of equality, for simplicity
            if(i >= absolute(j-(n-1)))
                cout<<"*  ";
            else 
                cout<<"   ";
        }
        cout<<"\n";
    }
}

void Square(int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout<<"*  ";
        }
        cout<<"\n";
    }
}

int main()
{
    cout<<"Enter the side\n";
    int n; cin>>n;

    if(n <= 0)
    {
        cout<<"Invalid input!";
        return 0;
    }

    cout<<"Drawing a sum-rectangle\n";
    SumRectangle(n);
    cout<<"Drawing a lower triangle\n";
    LowerTriangle(n);
    cout<<"Drawing an upper triangle\n";
    UpperTriangle(n);
    cout<<"Drawing a right-inverted lower triangle\n";
    RightInvertLow(n);
    cout<<"Drawing a righ-inverted upper triangle\n";
    RightInvertUp(n);
    cout<<"Drawing a triangle\n";
    Triangle(n);
    cout<<"Drawing an inverted triangle\n";
    InvertedTriangle(n);
    cout<<"Drawing a square\n";
    Square(n);
    return 0;
}