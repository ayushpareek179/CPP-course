#include <iostream>
#include <vector>
/*this code can be changed easily
vector can be replaced with list/forward_list/stack/queue etc. 
while making requisite changes in the methods*/
using namespace std;

int main()
{
    vector<int> vec;
    for(int i = 1; i <= 10; i++)
        vec.push_back(i); //pushes values at the front
        //even if it is beyond the stipulated size
    vector<int>::iterator itr = vec.begin();
    vec.insert(itr+2, 20); //inserts element at third position
    vec.erase(itr+5); //removes element at sixth position
    for(int i = 1; i <= 3; i++)
        vec.pop_back(); //removes elements from the end
    
    for(itr = vec.begin(); itr != vec.end(); itr++)
        cout<<*itr<<"\n";
    
    return 0;
}