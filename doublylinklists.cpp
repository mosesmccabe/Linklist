// Doubly linkedlists

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
};
Node *head = nullptr;

void insertTohead(int userInput)
{
    Node *temp = new Node();
    temp->data = userInput;
    temp->next = nullptr;
    temp->prev = nullptr;
    
    if (head == nullptr)
    {
        head = temp;
        return;
    }
    
    head->prev = temp;
    temp->next = head;
    head = temp;
    
}

void printLists()
{
    Node *temp = head;
    
    while(temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void ReverstP()
{
    Node *temp = head;
    while(temp->next != nullptr)
        temp = temp->next;
    head = temp;
    
   // temp = head;
    while(temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

void ReverstPrint(Node *temp)
{
    if(temp == nullptr)
        return;
    ReverstPrint(temp->next);
    cout << temp->data << " ";
}


int main()
{
    insertTohead(3);
    insertTohead(4);
    insertTohead(5);
    insertTohead(6);
    
    printLists();
    ReverstPrint(head);
    cout << endl;
    ReverstP();

    
    return 0;

}