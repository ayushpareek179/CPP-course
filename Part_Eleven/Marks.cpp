//Assignment #9 implemented using classes
#include <iostream>
using namespace std;

class StudentGrades
{
    private: 
    //data members
    unsigned int s1;
    unsigned int s2;
    unsigned int s3;
    long long rollNo;
    string name;
    public:
    //constructors
    StudentGrades(int,int,int,long long, string);
    StudentGrades(StudentGrades&);
    //accessors
    int getMarksSubject1(){return s1;}
    int getMarksSubject2(){return s2;}
    int getMarksSUbject3(){return s3;}
    long long getRollNumber(){return rollNo;}
    string getName(){return name;}
    //mutators
    void setMarksSubject1(unsigned int);
    void setMarksSubject2(unsigned int);
    void setMarksSubject3(unsigned int);
    void setRollNo(long long);
    //facilitators
    int totalMarks();
    char grade();
    //destructor
    ~StudentGrades(){cout<<"StudentGrades Object destroyed\n";}
};

int main()
{
    int a,b,c; long long r; string n;
    while(true) //taking valid inputs
    {
        cout<<"Enter the roll number\n";
        cin>>r;
        if(r < 0)
        {
            cout<<"Please enter a valid roll number\n";
            continue;
        }
        cout<<"Enter the name of the student\n";
        cin>>ws; getline(cin, n);
        cout<<"Enter the marks in three subjects\n";
        cin>>a>>b>>c;
        if(a < 0 || b < 0 || c < 0 || a > 100 || b > 100 || c > 100)
        {
            cout<<"Please enter positive marks between 0 and 100\n";
            continue;
        }
        break;
    }
    
    StudentGrades *ptr = new StudentGrades(a,b,c,r,n);
    cout<<"Name of the student is: "<<ptr->getName()<<"\n";
    cout<<"Roll Number: "<<ptr->getRollNumber()<<"\n";
    cout<<"Marks obtained in the three subjects:\n"<<ptr->getMarksSubject1();
    cout<<"\t"<<ptr->getMarksSubject2()<<"\t"<<ptr->getMarksSUbject3()<<"\n";
    cout<<"Total marks obtained: "<<ptr->totalMarks()<<"\n";
    cout<<"Grade assigned: "<<ptr->grade()<<"\n";
    ptr->~StudentGrades();

    return 0;
}

StudentGrades::StudentGrades(int x, int y, int z, long long a, string s)
{
    setMarksSubject1(x);
    setMarksSubject2(y);
    setMarksSubject3(z);
    setRollNo(a);
    name = s;
}
StudentGrades::StudentGrades(StudentGrades& sg)
{
    s1 = sg.s1;
    s2 = sg.s2;
    s3 = sg.s3;
    rollNo = sg.rollNo;
    name = sg.name;
}
void StudentGrades::setMarksSubject1(unsigned int a)
{
    if(a < 0 || a > 100)
        s1 = 0;
    else 
        s1 = a;
}
void StudentGrades::setMarksSubject2(unsigned int a)
{
    if(a < 0 || a > 100)
        s2 = 0;
    else 
        s2 = a;
}
void StudentGrades::setMarksSubject3(unsigned int a)
{
    if(a < 0 || a > 100)
        s3 = 0;
    else 
        s3 = a;
}
void StudentGrades::setRollNo(long long a)
{
    if(a < 0)
        rollNo = -a;
    else
        rollNo = a;
}
int StudentGrades::totalMarks()
{
    return s1+s2+s3;
}
char StudentGrades::grade()
{
    int tot = totalMarks();
    float g = tot/3;
    if(g >= 60)
        return 'A';
    else if(g >= 40 && g < 60)
        return 'B';
    else
        return 'C';
}
