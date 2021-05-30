//To demonstrate inner classes in C++
#include <iostream>
using namespace std;

class Table
{
    private:
    unsigned int n;
    class multiplication //inner class
    {
        private:
        int a; 
        int b;
        public:
        multiplication(int a, int b)
        {
            this->a = a;
            this->b = b;
        }        
        void product()
        {
            cout<<a<<" x "<<b<<" = "<<a*b<<"\n";
        }
    };
    public:
    Table(int a)
    {
        if(a > 0)
            n = a;
        else 
            n = 1;
    }
    void table()
    {
        for(int i = 1; i <= 10; i++)
        {
            multiplication m(n,i);
            m.product();
        }
    }
};

int main()
{
    cout<<"Enter a positive number\n";
    int n; cin>>n;
    Table t(n); t.table();
    cout<<"\n";
    /*Table::multiplication m(2,4); - can create an object if not private/protected
    m.product(); - can call public functions/members too, in that situation*/
    return 0;
}