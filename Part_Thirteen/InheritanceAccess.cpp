//To demonstrate how access specifiers influence inheritance
//A - Parent, B = Child, C = Grandchild
#include <iostream>
using namespace std;

class A
{
    private:
    int a;
    protected:
    int b;
    public:
    int c;
    void setter()
    {
        a = 1;
        b = 2;
        c = 3;
    }
    void getter()
    {
        printf("a = %d, b = %d, c = %d\n",a,b,c);
    }
};

class B:public A    
//private A prevents accessibility at lower levels
//protected works identical to public 
//it just prevents objects from accessing these
{
    private:
    char t;
    protected:
    char u;
    public:
    char v;
    void accessor()
    {
        setter();
        getter(); // a = 1, b = 2, c = 3
        //a = 5; - inaccessible private
        b++; //accessible protected
        c++; //accessible public
        getter(); // a = 1, b = 3, c = 4
    }
};

class C:public B
{
    public:
    void access()
    {
        //t = 'o'; - access denied
        u = '*';//available
        v = '{'; //available
        accessor();
        b++; //accessible protected
        c++; //accessible public
        getter(); 
    }
};

/*class D:public C
{
    public:
    void doer()
    {
        b++;
        c++;
    }
};*/

int main()
{
    /*B broccoli;
    broccoli.b = 10;
    inaceesible when A was inherited protected*/
    C cherry;
    /*cherry.c = 11; - works iff all inheritances are public*/ 
    cherry.access();
    return 0;
}