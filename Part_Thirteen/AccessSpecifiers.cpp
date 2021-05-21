//To demonstrate access specifiers with lecture's car example
#include <iostream>
using namespace std;

class MyCar
{
    private:
    string pistonTech;
    protected:
    string trademark;
    public:
    string paintColour;
    void setpisTec();
    void settrademark();
    void setpaiCol();
    void getFeatures();
};

void MyCar::setpisTec()
{
    pistonTech = "Steel";
}
void MyCar::settrademark()
{
    trademark = "International Car Company";
}
void MyCar::setpaiCol()
{
    paintColour = "Silver";
}
void MyCar::getFeatures()
{
    cout<<"Trademark: "<<trademark<<"\n";
    cout<<"Paint colour: "<<paintColour<<"\n";
    cout<<"Pistons: "<<pistonTech<<"\n";
}

class YourCar:public MyCar
{
    private:
    string newFeature; //can have its own features
    public:
    void setparams(string s)
    {
        //pistonTech = "Steel"; - Inaccessible
        setpisTec(); //cannot mutate 
        trademark = "Local Car Company"; //valid
        paintColour = s; //valid
        newFeature = "Best-in-class in La-la-land";
    }
    void getparams()
    {
        getFeatures(); //works
        cout<<newFeature<<"\n";
    }
};

class Customer//@@:public YourCar
{
    public:
    void tasks()
    {
        YourCar y;
        //Important observation - cannot access public members of the parent
        //class from derived class' object
        //y.newFeature = "Fake company"; - inaccessible
        cout<<"LCC\n";
        //y.paintColour = "Black"; - Inaccessible
        y.setparams("Black");
        y.getparams();
        //@@trademark = "XOXO";
        
        MyCar m;
        cout<<"ICC\n";
        m.paintColour = "Bronze"; //accessible
        m.setpisTec(); 
        m.settrademark();
        m.getFeatures();
        //m.trademark = "My Creation"; - inaccessible

        cout<<"\nCustomer says:\nTengo dos carros!\n";
    }
};
int main()
{
    Customer c;
    //c.setpisTec(); - not allowed
    //c.setparams(); - not allowed
    c.tasks();
    return 0;
}