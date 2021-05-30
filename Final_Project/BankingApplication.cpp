//Project to emulate a banking application
#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

class InsufficientBalance //exception class
{
    public:
    void displayLowInit()
    {
        cout<<"Initial deposit has to be more than $500\nPlease try again\n";
    }
    void displayLargeWithdraw()
    {
        cout<<"Too large withdrawal\nAt least $500 has to be maintained as minimum balance\nPlease try again\n";
    }
};

class Account
{
    private:
    string firstName;
    string lastName;
    double balance;
    int acctNum;
    static int lastAcctNum;
    
    public:
    Account(){}
    Account(string fName, string lName, double b);
    string getFirstName(){return firstName;}
    string getLastName(){return lastName;}
    double getBalance(){return balance;}
    int getAcctNum(){return acctNum;}
    void deposit(double amt);
    void withdraw(double amt);
    static int getlastAccountNum(); //unnecessary
    static void setlastAccountNum(int l); //to help account numbers to tally

    friend ostream& operator<<(ostream&, Account&);
    friend ifstream& operator>>(ifstream&, Account&);
    friend ofstream& operator<<(ofstream&, Account&);
    void display(); //implemented by ostream too
};

int Account::lastAcctNum = 0;
Account::Account(string fName, string lName, double b)
{
    acctNum = ++lastAcctNum;
    firstName = fName;
    lastName = lName;
    if(b >= 0)
    {
        balance = b;
        if(b < 500)
            throw InsufficientBalance();
    }
    else 
        balance = 0;
}
void Account::deposit(double amt)
{
    balance += amt;
}
void Account::withdraw(double amt)
{
    if(balance-amt < 500)
        throw InsufficientBalance();
    balance -= amt;
}
void Account::display()
{
    cout<<"Account-holder details:\n";
    cout<<"Account Number: "<<acctNum<<"\n";
    cout<<"First Name: "<<firstName<<"\n";
    cout<<"Last Name: "<<lastName<<"\n";
    cout<<"Balance: $"<<balance<<"\n";
}
void Account::setlastAccountNum(int l)
{
    lastAcctNum = l;
}
int Account::getlastAccountNum()
{
    return lastAcctNum;
}
ostream& operator<<(ostream& out, Account& a)
{
    a.display(); out<<"\n";
    return out;
}
ofstream& operator<<(ofstream& ofs, Account& a)
{
    ofs<<a.acctNum<<"\n";
    ofs<<a.firstName<<"\n";
    ofs<<a.lastName<<"\n";
    ofs<<a.balance<<"\n";
    return ofs;
}
ifstream& operator>>(ifstream& ifs, Account& a)
{
    ifs>>a.acctNum;
    ifs>>a.firstName;
    ifs>>a.lastName;
    ifs>>a.balance;
    return ifs;
}

class Bank
{
    private:
    map<int, Account>accounts; //active database
    public:
    Bank(); //loads preexisting data
    Account openAccount(string fName, string lName, double bal); //opens account and saves changes
    Account balanceEnquiry(int acctNum);
    Account deposit(int acctNum, double amt);
    Account withdraw(int acctNum, double amt);
    Account closeAccount(int acctNum); //deletes entry
    void showAllAccounts();
    ~Bank(); //updates outstanding changes from the database
};
Bank::Bank()
{
    ifstream infile("Bank info.txt");
    if(!infile.is_open())
    {
        cout<<"File does not exist!\n";
        return;
    }
    Account a;
    while(!infile.eof())
    {
        infile>>a;
        accounts.insert(pair<int, Account>(a.getAcctNum(), a));        
    }
    a.setlastAccountNum(a.getAcctNum());
    infile.close();
}
Account Bank::openAccount(string fName, string lName, double bal)
{
    Account a(fName, lName, bal);
    accounts.insert(pair<int, Account>(a.getAcctNum(), a));
    cout<<"Thanks for opening your account!\n";
    cout<<a<<"\n";

    ofstream outfile("Bank info.txt", ios::trunc);
    map<int, Account>::iterator itr = accounts.begin();
    while(itr != accounts.end())
    {
        outfile<<itr->second;
        itr++;
    }
    outfile.close(); 
    return a;
}
Account Bank::balanceEnquiry(int acctNum)
{
    map<int, Account>::iterator itr = accounts.find(acctNum);
    Account a("","",500);
    if(itr != accounts.end())
    {
        a = itr->second;
    }
    else 
        cout<<"Account the inputted number does not exist\n";
    return a;
}
Account Bank::deposit(int acctNum, double amt)
{
    map<int, Account>::iterator itr = accounts.find(acctNum);
    if(itr != accounts.end())
    {
        itr->second.deposit(amt);
        cout<<"Balance updated\n";
    }
    else 
        cout<<"Account the inputted number does not exist\n";
    return itr->second;
}
Account Bank::withdraw(int acctNum, double amt)
{
    map<int, Account>::iterator itr = accounts.find(acctNum);
    if(itr != accounts.end())
    {
        itr->second.withdraw(amt);
        cout<<"Balance updated\n";
    }
    else 
        cout<<"Account the inputted number does not exist\n";
    return itr->second;
}
Account Bank::closeAccount(int acctNum)
{
    map<int, Account>::iterator itr = accounts.find(acctNum);
    Account a("","",500);
    if(itr != accounts.end())
    {
        a = itr->second;
        accounts.erase(acctNum);
        cout<<"Account has been removed\n";
    }
    else 
        cout<<"Account the inputted number does not exist\n";
    return a;
}
void Bank::showAllAccounts()
{
    map<int, Account>::iterator itr = accounts.begin();
    while(itr != accounts.end())
    {
        cout<<itr->second<<"\n";
        itr++;
    }
}
Bank::~Bank()
{
    map<int, Account>::iterator itr = accounts.begin();
    ofstream ofs("Bank info.txt");
    while(itr != accounts.end())
    {
        ofs<<itr->second;
        itr++;
    }
    ofs.close();
}

int main()
{
    Bank bank;
    Account account;
    cout<<"Simple bank application\n\n";
    while(true)
    {
        cout<<"\t1. Open an account\n";
        cout<<"\t2. Balance enquiry\n";
        cout<<"\t3. Deposit\n\t4. Withdrawal\n";
        cout<<"\t5. Close an account\n";
        cout<<"\t6. Show all accounts\n";
        cout<<"\t7. Quit\n";
        int ch; cin>>ch;
        switch(ch)
        {
            case 1:
            {
                string f, l; double b;
                cout<<"Enter your first name: "; cin>>ws; cin>>f;
                cout<<"Enter your last name: "; cin>>ws; cin>>l;
                cout<<"Enter initial balance: "; cin>>b;
                try
                {
                    account = bank.openAccount(f,l,b);
                    cout<<account<<"\n";
                }
                catch(InsufficientBalance e)
                {
                    e.displayLowInit();
                }
                break;
            }
            case 2:
            {
                int a; cout<<"\nEnter your account number: "; cin>>a;
                account = bank.balanceEnquiry(a);
                cout<<account<<"\n";
                break;
            }
            case 3:
            {
                int a; double n; 
                cout<<"Enter your account number: "; cin>>a;
                cout<<"Enter the amount to be deposited: "; cin>>n;
                account = bank.deposit(a,n);
                cout<<account<<"\n";
                break;
            }
            case 4:
            {
                int a; double n; 
                cout<<"Enter your account number: "; cin>>a;
                cout<<"Enter the amount to be withdrawn: "; cin>>n;
                try
                {
                    account = bank.withdraw(a,n);
                    cout<<account<<"\n";
                }
                catch(InsufficientBalance e)
                {
                    e.displayLargeWithdraw();
                }
                break;
            }
            case 5:
            {
                int a; cout<<"Enter your account number: "; cin>>a;
                account = bank.closeAccount(a);
                cout<<"Account with following details deleted: \n"<<account<<"\n";
                break;
            }
            case 6:
            {
                bank.showAllAccounts();
            }
            case 7:
                cout<<"Operation terminated\n";
                break;
            default:
                cout<<"Incorrect option\nTry again\n\n";
        }
        if(ch == 7)
            break;
    }
    return 0;
}


