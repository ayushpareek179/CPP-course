//To demonstrate the basics of C++ arrays
#include <iostream>
using namespace std;
//Terribly coded as a single block - old school monolith
int main()
{
    cout<<"Initialize arrays as:\nDataType ArrayName[size] = {..List of values..}\n";
    int a[4] = {93,-62,117,-119};
    cout<<"Display the array effortlessly using\nfor(auto element:ArrayName)\n\n";
    for(auto e:a)
        cout<<e<<" ";
    cout<<"\t//Displayed using above syntax\n\n";

    cout<<"\n\nImplicitly changing the data type to char using:\nfor(char element:ArrayName)\n\n";
    for(char e:a)
        cout<<e<<" ";
    cout<<"\t//Implemented above and received ASCII equivalents\n";

    cout<<"\n\nThe erstwhile convention was to use:\n for(int i = 0; i<size; i++)\n";
    cout<<"Then, the elements would be 'subscripted' as ArrayName[index]\n\n";
    for(int i = 0; i < 4; i++)
        cout<<a[i]<<" ";
    cout<<"\t//Printed using the most popular convention just discussed";

    return 0;
}