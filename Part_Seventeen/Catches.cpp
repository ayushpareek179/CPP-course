//Multiple catch blocks and other variants
#include <iostream>
using namespace std;

class MyException {};
class childException:MyException {};
int main()
{
    try
    {
        try //nested try-catch
        {
            int *a = NULL;
            if(!a)
                throw exception();
            cout<<*a<<"\n";
        }
        catch(exception& e)
        {
            cout<<e.what()<<"\n";
        }
        int a = 0;
        if(a == 0)
            throw MyException();
        cout<<100/a;
        a = -1;
        if(a < 0)
            throw childException();
        int arr[a];
    }
    catch(childException e) //derived class(es) before parent class
    {
        cout<<"Child class exception\n";
    }
    catch(MyException e)
    {
        cout<<"Parent class exception\n";
    }
    catch(...) //all catch should be at the end
    {
        cout<<"Unknown exception\n";
    }
    return 0;
}