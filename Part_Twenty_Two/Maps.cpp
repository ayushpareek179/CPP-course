#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<int, string> m;
    m.insert(pair<int, string>(1, "Asfaqullah"));
    m.insert(pair<int, string>(2, "Jose"));
    m.insert(pair<int, string>(3, "Bob"));

    cout<<"Key and values:\n";
    m.erase(1); //removes the first index
    m.insert(pair<int, string>(2, "Piroutte")); //makes no change
    map<int, string>::iterator itr;
    for(itr = m.begin(); itr != m.end(); itr++)
    cout<<itr->first<<" "<<itr->second<<"\n";

    cout<<"Value search using key = 2\n";
    itr = m.find(2); //searching for value using key
    cout<<itr->first<<" "<<itr->second<<"\n";
    return 0;
}