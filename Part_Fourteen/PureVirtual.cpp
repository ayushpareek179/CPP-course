/*A program to show functional polymorphism via a "shape" generalization of 
a morbid square, an inadequate triangle and a loquacious circle*/
#include <iostream>
using namespace std;
class shape
{
    protected:
    unsigned short int sides;
    float sumIntAngle;
    public:
    shape(int s = 0)
    {
        if(s >= 0)
            sides = s;
        else 
            sides = 0;
        if(s >= 2)
            sumIntAngle = (2*s-4)*90;
        else if(s == 0)
            sumIntAngle = 360;
        else 
            sumIntAngle = 0;
    }
    virtual int displayNumSides() = 0;
    virtual float sumAngle() = 0;
    virtual void displaySide() = 0;
    virtual void displayAngle() = 0;
};
class square:public shape
{
    private:
    float s1,s2,s3,s4;
    float a1,a2,a3,a4;
    public:
    square(float side = 0, int s = 4):shape(s)
    {
        s4 = s3 = s2 = s1 = side;
        a1 = a2 = a3 = a4 = 90; 
    }
    int displayNumSides(){return sides;}
    float sumAngle(){return sumIntAngle;}
    void displaySide(){cout<<"All sides are: "<<s1<<" units\n";}
    void displayAngle(){cout<<"All angles are: "<<90.0<<" degrees\n";}
};
class triangle:public shape
{
    private:
    float s1, s2, s3;
    float a1, a2, a3;
    public:
    triangle(float s1, float s2, float s3, float a1, float a2, float a3, int s = 3):shape(s)
    {
        if(s1+s2 >= s3 && checkneg(s1) && checkneg(s2) && checkneg(s3))
        {
            this->s1 = s1;
            this-> s2 = s2;
            this->s3 = s3;
        }
        else 
        s1 = s2 = s3 = 0;        
        if(int(a1+a2+a3) == 180 && checkneg(a1) && checkneg(a2) && checkneg(a3))
        {
            this->a1 = a1;
            this->a2 = a2;
            this->a3 = a3;
        }
        else 
        a1 = a2 = a3 = 0;
    }
    bool checkneg(float s)
    {
        if(s > 0)
            return true;
        return false;
    }
    int displayNumSides(){return sides;}
    float sumAngle(){return sumIntAngle;}
    void displaySide(){printf("Sides are:\n%f units\n%f units\n%f units\n",s1,s2,s3);}
    void displayAngle(){printf("Angles are:\n%f degrees\n%f degrees\n%f degrees\n",a1,a2,a3);}
};
class circle:public shape 
{
    private:
    float radius;
    public:
    circle(float r, int s = 0):shape(s)
    {
        if(r > 0)
            radius = r;
        else 
            radius = 0;
    }
    int displayNumSides(){return sides;}
    float sumAngle(){return sumIntAngle;}
    void displaySide(){cout<<"The radius of circle is: "<<radius<<" units\n";}
    void displayAngle(){cout<<"The total angle around the centre is: "<<360.00<<" degrees\n";}
};

int main()
{
    float s1, s2, s3, a1, a2, a3;

    cout<<"Enter the square's side:\n"; cin>>s1;
    shape *base = new square(s1);
    cout<<"Number of sides in a square is "<<base->displayNumSides()<<"\n";
    cout<<"Sum of interior angles of a square is "<<base->sumAngle()<<"degrees\n";
    base->displaySide(); base->displayAngle();
    delete base;

    cout<<"Enter the triangle's sides:\n"; cin>>s1>>s2>>s3;
    cout<<"Enter the triangle's angles:\n"; cin>>a1>>a2>>a3;
    base = new triangle(s1,s2,s3,a1,a2,a3);
    cout<<"Number of sides in a triangle is "<<base->displayNumSides()<<"\n";
    cout<<"Sum of interior angles of a triangle is "<<base->sumAngle()<<"degrees\n";
    base->displaySide(); base->displayAngle();
    delete base;

    cout<<"Enter the circle's radius:\n"; cin>>s1;
    base = new circle(s1);
    cout<<"A circle has "<<base->displayNumSides()<<" sides!\n";
    cout<<"Both a point and a circle encompass "<<base->sumAngle()<<" degrees\n";
    base->displaySide(); base->displayAngle();
    delete base;

    return 0;
}

