//Student Exercise #11
#include <iostream>
using namespace std;

class Employee
{
    private:
    long empID;
    string empName;
    public:
    Employee(long e = 0, string n = "Unspecified")
    {
        if(e > 0)
            empID = e;
        else 
            empID = -1;
        empName = n;
    }
    long getID(){return empID;}
    string getName(){return empName;}
};

class FullTime:public Employee
{
    private:
    double salary;
    public:
    FullTime(long i, string n, double s):Employee(i,n)
    {
        if(s > 0)
            salary = s;
        else 
            salary = 5000; //minimum salary
    }
    double getSalary(){return salary;}
    friend ostream& operator<<(ostream&, FullTime&);
};

class PartTime:public Employee
{
    private:
    double dailyWage;
    public:
    PartTime(long i, string n, double d):Employee(i,n)
    {
        if(d > 0)
            dailyWage = d;
        else 
            dailyWage = 150; //minimum daily wage
    }
    double getDailyWage(){return dailyWage;}
    friend ostream& operator<<(ostream&, PartTime&);
};

ostream& operator<<(ostream& out, FullTime& obj)
{
    out<<obj.getID()<<"\t"<<obj.getName()<<"\t"<<obj.getSalary();
    return out;
}

ostream& operator<<(ostream& out, PartTime& obj)
{
    out<<obj.getID()<<"\t"<<obj.getName()<<"\t"<<obj.getDailyWage();
    return out;
}

int main()
{
    cout<<"Enter employee ID, name and daily wage\n";
    string name; long id; double earn;
    cin>>id>>name>>earn;
    PartTime e1(id, name, earn);
    cout<<"\nEnter employee ID, name and salary\n";
    cin>>id>>name>>earn;
    FullTime e2(id, name, earn);

    cout<<"ID\tName\tDaily Wage/Salary\n";
    cout<<e1<<"\n";
    cout<<e2<<"\n";

    return 0;
}