//To calculate sum of N-natural numbers via different methods
//std::chrono - https://www.geeksforgeeks.org/measure-execution-time-function-cpp/
#include <iostream>
#include <ctime>
using namespace std;

long long SumFormula(long long n)
{
    long long sum = n*(n+1)/2;
    return sum;
}

long long SumLoop(long long n)
{
    long long sum = 0;
    for(long long i = 1; i <= n; i++)
    sum += i;
    return sum;
}

int main()
{
    cout<<"Enter a positive integer\n";
    long long num; cin>>num;

    if(num <= 0)
    cout<<"Invalid input\n";
    else
    {
        clock_t t = clock();
        cout<<"Using the formula: "<<SumFormula(num)<<"\n";
        t = clock() - t;
        cout<<"Time taken: "<<(double)t/CLOCKS_PER_SEC<<"\n";

        t = clock();
        cout<<"Using the loop: "<<SumLoop(num)<<"\n";
        t = clock() - t;
        cout<<"Time taken: "<<(double)t/CLOCKS_PER_SEC;
    }
}