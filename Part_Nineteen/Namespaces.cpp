//To demonstrate namespaces in C++
#include <iostream>
#include <string>
using namespace std;

namespace one
{
    void display()
    {
        cout<<"One's display called\n";
    }
    int add(int x, int y)
    {
        return (x+y);
    }
}

namespace two
{
    string binary(int x)
    {
        string s = "", r = "";
        while(x != 0)
        {
            s += to_string(x%2);
            x = x/2;
        }
        for(int i = s.length() - 1; i >= 0; i--)
            r += s[i];
        return r;
    }
    void display()
    {
        cout<<"Two's display called\n";
    }
    int add(int x, int y)
    {
        return stoi(binary(x+y));
    }
}

using namespace two;
int main()
{
    display(); 
    cout<<"Sum of 25 and 40 is: "<<add(25,40)<<" in binary terms\n";
    one::display();
    cout<<"Cross-verification: "<<binary(one::add(25,40))<<"\n";
    return 0;
}