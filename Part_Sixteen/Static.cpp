#include <iostream>
using namespace std;

class Car
{
    private:
    static int carNo;
    string color;
    long locPIN;
    public:
    static double price;
    Car(string c = "Default - Black", long l = 110342)
    {
        carNo++; //counter of sales
        color = c;
        if(l > 99999)
            locPIN = l;
        else 
            locPIN = 110342;        
    }
    static double getPrice()
    {
        return price;
    }
    static int getSales()
    {
        return carNo;
    }
    string getColor(){return color;}
    long getPIN(){return locPIN;}
};
int Car::carNo = 0;
double Car::price = 500000;

int main()
{
    string c; long n;
    cout<<"Universal price of the model was: "<<Car::getPrice()<<"\n";
    Car::price = 1000000; //direct access without creating even a single object 
    for(int i = 0; i < 3; i++)
    {
        cout<<"Enter the colour and PIN location of car sold:\n";
        cin>>c>>n;
        Car* a = new Car(c,n);
        cout<<"Car colour: "<<a->getColor()<<"\n";
        cout<<"Location of sale: "<<a->getPIN()<<"\n";
        cout<<"Car price: "<<a->getPrice()<<"\n\n";
        delete a;
    }
    cout<<"Total sales made: "<<Car::getSales()<<"\n";
    return 0; 
}