#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

// head node
Node *head = nullptr;

// create a new node
void InsertToBegining( )
{
    int max, userInput;
    cout << "How many numbers do you want to insert? ";
    cin >> max;
    
    for (int i = 0; i < max; i++)
    {
        cout << "Enter the number: ";
        cin >> userInput;
        
        // create lists
        Node *temp = new Node();
        temp->data = userInput;
        temp->next = head;
        head = temp;
    }
}

// Inserting to any position
void InsertToPosition(int value, int position)
{
    Node *temp1 = new Node();
    temp1->data = value;
    temp1->next = nullptr;
    
    if(position == 1)
    {
        temp1->next = head;
        head = temp1;
        return;
    }
    
    Node *temp2 = head;
    for(int i = 0; i < position - 2; i++)
    {
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
}

// Delete
void Delete(int position)
{
    Node *temp1 = head;   //good
    
    if(position == 1)
    {
        head = temp1->next;
        delete temp1;
        return;
    }
    
    
    for(int i = 0; i < position - 2; i++)
        temp1 = temp1->next;
    
    Node *temp2 = temp1->next;    //good
    temp1->next = temp2->next;
    delete temp2;
}

// Reverse lists
void ReverseLists()
{
    Node *prev, *current, *next;
    prev = nullptr;
    current = head;
    
    while(current != nullptr)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

// Use Recursion to print
void RecursionReversePrint(Node *temp )
{
    if(temp == nullptr)
        return;
    RecursionReversePrint(temp->next);
    cout << temp->data << " ";
}

// Use Recursion to reverse lists
void RecursionReverseLists(Node *temp )
{
    if(temp == nullptr)
        return;
    RecursionReverseLists(temp->next);
    Node *temp2 = temp->next;
    temp2->next = temp;
    temp = nullptr;
    
}

// print list
void Print()
{
    Node *temp = head;
    while(temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}



int main()
{
    enum {one = 1, two, three, four, five, six};
    int option;
    char mainmenu = 'y';
    
    while(mainmenu == 'y')
    {
        // create menu
        cout << "Select for the list below\n"
             << "1 - Insert to Lists\n"
             << "2 - Insert to a position\n"
             << "3 - Delete\n"
             << "4 - Reverse Lists\n"
             << "5 - Reverse Lists Using Recursion\n"
             << "6 - Print Lists\n"
             << "Enter a option: ";
        cin >> option;
    
        switch(option)
        {
            case one:
                InsertToBegining();
                cout << "\nReturn to Menu(y/n): ";
                cin >> mainmenu;
            break;
            case two:
                int value, location;
                cout << "Enter value: ";
                cin >> value;
                cout << "Enter location: ";
                cin >> location;
                InsertToPosition(value, location);
                cout << "\nReturn to Menu(y/n): ";
                cin >> mainmenu;
            break;
            case three:
                int position;
                cout << "Enter Index location: ";
                cin >> position;
                Delete(position);
                cout << "\nReturn to Menu(y/n): ";
                cin >> mainmenu;
            break;
            case four:
                ReverseLists();
                Print();
                cout << "\nReturn to Menu(y/n): ";
                cin >> mainmenu;
                break;
            case five:
                RecursionReverseLists(head);
                cout << endl;
                cout << "\nReturn to Menu(y/n): ";
                cin >> mainmenu;
                break;
            case six:
                Print();
                cout << "\nReturn to Menu(y/n): ";
                cin >> mainmenu;
            break;
        }
    }
    
    
    return 0;
}