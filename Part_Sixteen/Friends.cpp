//To depict friend classes and functions
#include <iostream>
using namespace std;

class Friend;
class Person
{
    private:
    string name;
    protected:
    int age;
    public:
    char gender;
    Person(string n = "Unspecified", int a = 0, char g = 'N')
    {
        name = n;
        if(a >= 0)
            age = a;
        else 
            age = 0;
        if(g > 97)
            g = g - 32;
        if(g == 'M' || g == 'F' || g == 'O')
            gender = g;
        else 
            gender = 'N';
    }
    //Cannot introduce myself! I'm shy.
    friend Friend;
    //What about authorities?
    friend void authority(Person);
};
class Friend
{
    public:
    Person p;
    Friend(Person anybody)
    {
        p = anybody;
    }
    void intro()
    {
        cout<<"Hello everyone!\n";
        cout<<"This is my friend, "<<p.name<<"\n"; //inacessible unless befriended
        cout<<"My friend's age is "<<p.age<<" years\n"; //inacessible unless befriended/inherited
        cout<<"My friend identifies as a ";
        if(p.gender == 'M') //accessible anyway
            cout<<"male";
        else if(p.gender == 'F')
            cout<<"female";
        else 
            cout<<"non-binary gender";
        cout<<"\n";
    }
};
void authority(Person anybody)
{
    Person A = anybody;
    cout<<"So, following shall be registered as your credentials:\n";
    cout<<"Name\t\tAge\t\tGender\n";
    cout<<A.name<<"\t\t"<<A.age<<"\t\t"<<A.gender<<"\n";
}

int main()
{
    cout<<"Enter a name, age and gender (M for male, F for female, O for others):\n";
    string a;int b; char c; cin>>a>>b>>c;
    //Person::gender = 'M'; - non static
    Person Somebody(a,b,c);
    Friend f(Somebody); f.intro(); cout<<"\n";
    authority(Somebody);
    
    return 0;
}