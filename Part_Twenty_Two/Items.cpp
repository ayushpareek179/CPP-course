//Student Exercise #15
//Vectorized implementation of Student Exercise #14
//Part_Twenty_One's ItemList.cpp

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

//Class Product and its member methods
class Product
{
    private:
    string name;
    double price;
    int qty;
    public:
    Product(string n = "Duracell Batteries", double d = 100, int q = 1)
    {
        setName(n);
        setPrice(d);
        setQty(q);
    }
    string getName(){return name;}
    double getPrice(){return price;}
    int getQty(){return qty;}
    void setName(string n){name = n;}
    void setQty(int);
    void setPrice(double);
    void display();
    friend istream& operator>>(istream&, Product&);
    friend ifstream& operator>>(ifstream&, Product&);
    friend ostream& operator<<(ostream&, Product&);
    friend ofstream& operator<<(ofstream&, Product&);
};
void Product::setQty(int q)
{
    if(q > 0)
        qty = q;
    else 
        qty = 1;
}
void Product::setPrice(double d)
{
    if(d > 0)
        price = d;
    else 
        price = 100;
}
void Product::display()
{
    cout<<"Name of the product: "<<name;
    cout<<"\nProduct price: "<<price;
    cout<<"\nProduct quantity: "<<qty<<endl;
}

//Overloaded operators - friend functions
ostream& operator<<(ostream& out, Product& pr)
{
    cout<<"Press 1 to display formatted object-details\n";
    int ch; cin>>ch;
    if(ch == 1)
        pr.display();
    else 
        out<<pr.getName()<<"\n"<<pr.getPrice()<<"\n"<<pr.getQty()<<"\n";
    return out;
}
istream& operator>>(istream& in, Product& pr)
{
    string s; double d; int q;
    cout<<"Enter the product name: "; 
    in>>ws; getline(in, s);
    cout<<"Enter the product price: "; in>>d;
    cout<<"Enter the product quantity: "; in>>q;
    pr.setName(s); pr.setPrice(d); pr.setQty(q);
    return in;
}
ofstream& operator<<(ofstream& fos, Product& pr)
{
    fos<<pr.getName()<<"\n";
    fos<<pr.getPrice()<<"\n";
    fos<<pr.getQty()<<"\n";
    return fos;
}
ifstream& operator>>(ifstream& fin, Product& pr)
{
    string s; double d; int q;
    fin>>ws; getline(fin,s);
    fin>>d; fin>>q;
    pr.setName(s); pr.setPrice(d); pr.setQty(q);
    return fin;
}

//Helper functions
void clear() //To clear Items.txt
{
    ofstream ofs("Item List.txt", ios::trunc);
    ofs.close();
}
void setSize(int* s) //Helper for sizeToFile(int*, int*)
{
    while(true)
    {
        cout<<"Enter number of products\nYou've entered: ";
        cin>>*s; cout<<"\n";
        if(*s > 0) 
            break;
        else 
            cout<<"Invalid input, try again\n";
    }
}
void sizeToFile(int* s, int* flag) //for inputting size from user
{
    ofstream ofs("Latest Size.txt", ios::trunc);
    setSize(s);
    ofs<<*s; ofs.close(); 
    *flag = 0;
    clear();
}
void display(int size, vector<Product*> vec) //Displaying a vector's contents
{
    vector<Product*>::iterator itr;
    for(itr = vec.begin(); itr != vec.end(); itr++)
    {
        Product* p = *itr;
        p->display();
    }
}

//I/O functions
void write(int size, vector<Product*>& vec) 
{
    ofstream outfile("Item List.txt", ios::trunc);
    for(int i = 0; i < size; i++)
    {
        Product* pro = new Product();
        cin>>*pro;
        vec.push_back(pro);
        outfile<<*pro;
    }
    outfile.close();
}
bool read(int size, vector<Product*>& vec)
{
    ifstream inp("Item List.txt");
    if(inp.is_open())
    {
        for(int i = 0; i < size; i++)
        {
            Product* pro = new Product(); //cannot be outside the loop 
            inp>>*pro;
            vec.push_back(pro);           
        }
    }
    else 
    {
        cout<<"File does not exist\n";
        return false;
    }
    inp.close();
    return true;
}

int main()
{
    /*To take list size from file or to input
    it from concole and save into the file*/
    ifstream ifs("Latest Size.txt");
    int size, lflag = 1; 
    if(ifs.is_open())
    {
        string s; getline(ifs,s);
        if(s.length() != 0)
            size = stoi(s);
        else 
            sizeToFile(&size, &lflag);
    }
    else 
        sizeToFile(&size, &lflag);
    ifs.close();
    //create a vector of type Product*
    vector<Product*> vec;

    //Menu to write, read or clear the file
    cout<<"Enter your choice\n";
    cout<<"1. Write object to the file\n";
    
    if(lflag) //Cannot choose to read if empty
        cout<<"2. Read object from the file\n";

    cout<<"You have entered: "; int ch; cin>>ch;

    if(!lflag && ch == 2) //Cannot choose to read if empty
        ch = 0;
    
    switch(ch)
    {
        case 1:
            cout<<"Writing to the file\n";
            write(size, vec);
            cout<<"Finished writing\n";
            cout<<"Objects entered:\n";
            display(size, vec);
            break;
        
        case 2:
            cout<<"Reading from the file\n";
            if(read(size, vec))
            {
                cout<<"Finished reading\n";
                cout<<"File contents:\n";
                display(size, vec);
            }
            clear();
            break;
        
        default:
            cout<<"Invalid input\n";        
    }
    cout<<"Program terminated\n";

    if(ch == 2) //If you choose to read, the product list is cleared
    {
        ofstream out("Latest Size.txt", ios::trunc);
        out.close();
    }

    return 0;
}
