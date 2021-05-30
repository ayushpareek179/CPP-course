//To depict template classes via stack's implementation
#include <iostream>
using namespace std;

template <typename type>
class Stack
{
    private:
    type* stack;
    int capacity; 
    int top;
    public:
    Stack(int capacity)
    {
        if(capacity > 0)
            this->capacity = capacity;
        else 
            capacity = 0;
        top = -1;
        stack = new type[capacity];
    }
    void push(type);
    type pop();
    void display();
    ~Stack(){};
};

template <typename type>
void Stack<type>::push(type value)
{
    if(top == capacity-1)
        cout<<"Stack is full\n";
    else 
        stack[++top] = value;
}

template <typename type>
type Stack<type>::pop()
{
    if(top == -1)
    {
        cout<<"Stack is empty\n";
        return 0;
    }
    return stack[top--];
}

template <typename type>
void Stack<type>::display()
{
    if(top > -1)
    {
        cout<<"Stack elements are:\n";
        for(int i = top; i >= 0; i--)
            cout<<stack[i]<<"\n";
    }
    else 
        cout<<"Stack is empty\n";
}

int main()
{
    int cap;
    while(true)
    {
        cout<<"Enter the stack capacity\n";
        cin>>cap; 
        if(cap <= 0)
            cout<<"Invalid input. Try again.\n";
        else 
            break;
    }
    Stack<string>* s = new Stack<string>(cap);
    //cout<<"Choose stack type\n1. Integral\n2. Floating point\n3. Characters\n4.Strings\n"; - seperate code for each type
    while(true)
    {
        cout<<"Choose an option:\n1. Push\n2. Pop\n3. Display\n4. Quit\n"; cin>>cap;
        switch(cap)
        {
            case 1:
            {
                cout<<"Enter the element\n";
                //cin>>cap; s->push(cap); - for int stack
                string st; cin>>ws; getline(cin,st); s->push(st);
                break;
            }
            case 2:
                cout<<"Element popped: "<<s->pop()<<"\n";
                break;
            case 3:
                s->display();
                break;
            case 4:
                cout<<"Final stack status:\n";
            break;
            default:
                cout<<"Invalid option. Try again.\n";
        }
        if(cap == 4)
        {
            s->display();
            break;
        }
    }
    cout<<"Program terminated\n";
    return 0;
}