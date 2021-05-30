#include <iostream>
using namespace std;


class StackOverFlow
{
    public:
    void display()
    {
        cout<<"Overflow\nCannot push elements\nStack is full\n";
    }
};
class StackUnderFlow
{
    public:
    void display()
    {
        cout<<"Underflow\nCannot pop elements\nStack is empty\n";
    }
};
class NegCap
{
    public:
    void display()
    {
        cout<<"Stack's capacity should be positive\n";
    }
};

class Stack
{
    private:
    int* a = NULL;
    int cap;
    int top;
    public:
    Stack(int c)
    {
        if(c <= 0)
            throw NegCap();
        cap = c;
        a = new int[cap];
        top = -1;
    }
    void push(int n)
    {
        if(top == (cap-1))
            throw StackOverFlow();
        else 
            a[++top] = n;
    }
    int pop()
    {
        if(top == -1)
            throw StackUnderFlow();
        return a[top--]; 
    }
    void display()
    {
        if(top >= 0)
        {
            for(int i = top; i >= 0; i--)
                cout<<a[i]<<"\n";
            cout<<"\n";
        }
    }
    ~Stack(){};
};

int main()
{
    try 
    {
        cout<<"Enter stack capacity\n";
        int c; cin>>c;
        Stack* s = new Stack(c);
        while(true)
        {
            cout<<"Press 1 to push\nPress 2 to pop\nPress 3 to view the stack\nPress 0 to quit\n";
            int a; cin>>a;
            if(a == 0)
                break;
            else if(a == 1) //Push
            {
                try 
                {
                    cout<<"\nEnter a number\n";
                    int n; cin>>n;
                    s->push(n);
                }
                catch(StackOverFlow e)
                {
                    e.display();
                    break; //comment out to prevent breaking the loop
                }
            }
            else if(a == 2) //Pop
            {
                try 
                {
                    cout<<"\nElement popped: "<<s->pop()<<"\n";
                }
                catch(StackUnderFlow e)
                {
                    e.display();
                    break; //comment out to prevent breaking the loop
                }
            }
            else if(a == 3) //Display
            {
                cout<<"Stack elements are:\n";
                s->display();
            }
            else 
            cout<<"\nInvalid input\nTry again\n\n";
        }
        cout<<"\nFinally, the stack looks as:\n";
        s->display();
        s->~Stack();
    }
    catch(NegCap e)
    {
        e.display();
    }
    return 0;
}