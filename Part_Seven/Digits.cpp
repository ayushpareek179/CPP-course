/* To print the digits in a numeric input and:
    1. Check if is a narcisstic/Armstrong number
    2. Display its reverse
    3. Check if it is a palindrom number
    4. Display the number in words, digitwise
*/
#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

ll Digits(ll n, int key)
{
    int digitCount = 0;
    ll revNumber = 0, nn = n;
    while(n != 0)
    {
        if(key == 1) //isArmstrong(n,1)
            digitCount++;
        if(key == 2) //isArmstrong(n,2)
            revNumber = revNumber*10 + n%10;      
        if(key == 0) //to print digits
        {
            cout<<n%10;
            cout<<" ";
        }
        n /= 10;
    }
    if(key == 0)
        cout<<"\n";
    
    if(key == 1)
        return digitCount;
    if(key == 2)
        return revNumber;
    return nn;
} 

void isArmstrong(ll n)
{
    int index = Digits(n,1);
    ll sum = 0, nn = n;
    while(n > 0)
    {
        sum += pow(n%10, index);
        n /= 10;
    }
    if(sum == nn)
    {
        cout<<nn<<" is an Armstrong number\nThe sum of its digits' raised ";
        cout<<" to the number of digits in it is equal to the number itself";
    }
    else 
    {
        cout<<"Sum of digits of "<<nn<<", each raised to the number of digits in it is "<<sum;
        cout<<"\nThus, it is not an Armstrong number";
    }
}

void isPalindrome(ll n)
{
    if(n == Digits(n,2))
    cout<<n<<" remains the same on being reversed.\nThus, it is a palindrome number";
    else 
    cout<<n<<" isn't the same as its reversed form.\nThus, it isn't a palindrome number";
}

void DisplayWords(ll n)
{
    cout<<n<<" in words, digitwise:\n";
    ll rev = Digits(n, 2);
    while(rev != 0)
    {
        switch(rev%10)
        {
            case 0: cout<<"zero "; break;
            case 1: cout<<"one "; break;
            case 2: cout<<"two "; break;
            case 3: cout<<"three "; break;
            case 4: cout<<"four "; break;
            case 5: cout<<"five "; break;
            case 6: cout<<"six "; break;
            case 7: cout<<"seven "; break;
            case 8: cout<<"eight "; break;
            case 9: cout<<"nine "; break;
        }
        rev /= 10;
    }
    cout<<"\n";
}

int main()
{
    cout<<"Enter a positive number\n";
    ll num; cin>>num;

    if(num < 0)
    cout<<"Invalid input!";
    else 
    {
        DisplayWords(num);
        cout<<"Digits of the input are:\n"; num = Digits(num, 0); //stray zero bug fix
        isArmstrong(num);
        cout<<"\nThe reversed number is "<<Digits(num, 2);
        cout<<"\n";
        isPalindrome(num);
    }
}