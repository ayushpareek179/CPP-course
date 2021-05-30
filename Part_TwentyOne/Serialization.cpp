//Demonstrating serialization - storing and retrieving an object's state
#include <fstream>
#include <iostream>
using namespace std;

class Student
{
    private:
    string name;
    long rollNo;
    string department;
    static int a;

    public:
    Student(string n = "", long r = 0, string d = "")
    {
        setName(n);
        setRollNo(r);
        setDepartment(d);
    }
    
    void setName(string s){name = s;}
    void setRollNo(long l)
    {
        if(l > 0)
            rollNo = l;
        else 
            rollNo = ++a;
    }
    void setDepartment(string s){department = s;}    

    string getName(){return name;}
    long getRollNo(){return rollNo;}
    string getDepartment(){return department;}

    void display()
    {
        cout<<"Name of the student: "<<name;
        cout<<"\nRoll number of the student: "<<rollNo;
        cout<<"\nDepartment of the student: "<<department<<"\n";
    }
    friend ofstream& operator <<(ofstream&, Student&);
    friend ifstream& operator >>(ifstream&, Student&);
};
int Student::a = 0;

ofstream& operator <<(ofstream& ofs, Student& s)
{
    ofs<<s.getName()<<"\n"<<s.getRollNo()<<"\n"<<s.getDepartment()<<"\n";
    return ofs;
}

ifstream& operator >>(ifstream& ifs, Student& s)
{
    string inName, finName, inDept, finDept; long c;
    ifs>>inName>>finName>>c>>inDept>>finDept;
    
    s.setName(inName+" "+finName);
    s.setRollNo(c);
    s.setDepartment(inDept+" "+finDept);

    return ifs;
}

Student write()
{
    string name, dept; long roll;
    cout<<"Enter the student's name:\n";
    cin>>ws; getline(cin,name);
    cout<<"Enter the roll number:\n";
    cin>>roll;
    cout<<"Enter the student's department:\n";
    cin>>ws; getline(cin, dept);
    
    Student s(name,roll,dept);
    ofstream out("Student Serialization.txt",ios::trunc);
    out<<s;
    out.close();
    return s;
}

Student read()
{
    Student s;
    ifstream in("Student Serialization.txt");
    if(in.is_open())
        in>>s;
    in.close();
    return s;
}

int main()
{
    int ch = 0; Student s;
    cout<<"1. Enter student details\n2. Retrieve student details\n3. Do both\n";
    cout<<"Your choice: ";cin>>ch;
    switch(ch)
    {
        case 1:
        s = write();
        cout<<"File has been populated\n";
        cout<<"Details:\n";
        s.display();
        cout<<"\n";
        break;

        case 2:
        s = read();
        cout<<"File has been read\n";
        cout<<"Details:\n";
        s.display();
        cout<<"\n";
        break;

        case 3:
        s = write();
        cout<<"File has been populated\n";
        s = read(); cout<<"\n";
        cout<<"File has been read\n";
        cout<<"Details (formatted):\n";
        s.display();cout<<"\n";
        break;

        default:
        cout<<"Invalid entry\n";
    }
    cout<<"\nProgram terminated\n";
    return 0;
}