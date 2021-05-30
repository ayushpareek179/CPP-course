//Student Exercise #14
//Can be improved
#include <fstream>
#include <iostream>
using namespace std;

class Product
{
    private:
    string productName;
    double productPrice;
    unsigned int productQuantity;
    public:
    Product(string pn = "", double pp = 0, unsigned int pq = 0)
    {
        setProductName(pn);
        setProductPrice(pp);
        setProductQuantity(pq);
    }
    void setProductName(string pn)
    {
        productName = pn;
    }
    void setProductPrice(double);
    void setProductQuantity(unsigned int pq)
    {
        productQuantity = pq;
    }
    void display();
    friend ofstream& operator<<(ofstream&, Product&);
    friend ifstream& operator>>(ifstream&, Product&); 
};

void Product::display()
{
    cout<<"Name of the product: "<<productName<<"\n";
    cout<<"Price of the product: $"<<productPrice<<"\n";
    cout<<"Product quantity: "<<productQuantity<<"\n";
}

void Product::setProductPrice(double pp)
{
    if(pp > 0)
        productPrice = pp;
    else 
        productPrice = 100;
    //the default price 
}

ofstream& operator<<(ofstream& out, Product& pro)
{
    cout<<"Writing contents to the file..\n";
    out<<pro.productName<<"\n";
    out<<pro.productPrice<<"\n";
    out<<pro.productQuantity<<"\n";
    cout<<"Done\n";
    return out;
}

ifstream& operator>>(ifstream& in, Product& pro)
{
    cout<<"Reading file contents..\n";
    string s; double p; unsigned int q;
    in>>ws; getline(in,s);
    in>>p>>q;
    pro.setProductName(s);
    pro.setProductPrice(p);
    pro.setProductQuantity(q);
    //in>>q; //to reach file's end
    cout<<"Done\n";
    return in;
}

Product* write()
{
    string s; double p; unsigned int q;
    cout<<"Enter the product name: "; cin>>ws; getline(cin,s);
    cout<<"Enter the product price: "; cin>>p;
    cout<<"Enter the product quantity: "; cin>>q;
    cout<<"\n";

    Product* pr = new Product(s, p, q);
    
    ofstream out("Items.txt", ios::app);
    out<<*pr; out.close();

    return pr;
}

int main()
{
    cout<<"Enter number of items\n"; int n; 
    cout<<"You've entered: "; cin>>n;
    Product* product[n], indPro;
    cout<<"\nEnter your choice:\n";
    cout<<"1. Write to the file\n2. Read from the file\n3. Do both\n4. Clear file contents\n";
    cout<<"Your choice: "; int ch; cin>>ch;
    switch(ch)
    {
        case 3:
        case 1:
        for(int i = 0; i <n; i++)
        {
            product[i] = write();
            cout<<"Object entered:\n";
            product[i]->display();
        }
        if(ch == 1)
            break;

        case 2:
        {
            cout<<"File contents:\n";
            int burner;
            ifstream in("Items.txt");
            for(int i = 0; i < n; i++)
            {
                in>>indPro;
                product[i] = &indPro;
                product[i]->display();
                cout<<"\n";
            }
            if(ch == 2)
                break;
        }

        case 4:
        {
            if(ch == 3)
                break;
            fstream fio;
            fio.open("Items.txt", ios::trunc);
            fio.close();
            break;
        }

        default:
            cout<<"Invalid input\n";        
    }
    cout<<"Program terminated\n";
    return 0;
}