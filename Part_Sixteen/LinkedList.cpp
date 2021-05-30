//Simple linked list class
#include <iostream>
using namespace std;

class Node
{
    public:
    Node* next;
    int data;
};

void traversal(Node* n)
{
    cout<<"Node elements: \n";
    while(n != NULL)
    {
        cout<<n->data<<"\n";
        n = n->next;
    }
}

int length(Node* n)
{
    int i = 0;
    while(n != NULL)
    {
        n = n->next;
        i++;
    }
    return i;
}

Node* push(Node *n, int data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = n->next;
    n->next = newNode;
    return newNode;
}

Node* desired(Node* n, int in)
{
    int a = 1;
    while(a != in)
    {
        n = n->next;
        a++;
    }
    return n;
}

int main()
{
    Node* end = NULL;
    Node* head = new Node();
    head->data = 1;
    head->next = NULL;

    end = push(head, 2); //pushing at the end
    end = push(desired(head, length(head)), 3); //to push at the end => same as above
    end = push(desired(head, length(head)-1), 4); //pushing somewhere in the middle
    end = push(desired(head, length(head)-2), 5); //pushing somewhere in the middle
    
    cout<<"Node length: "<<length(head)<<"\n";
    traversal(head);
}