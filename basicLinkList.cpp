#include <iostream>
using namespace std;

struct Node
{
    int x;
    int *n;
};


int main()
{
    // head pointer
    int * head;
    Node fun1;
    Node fun2;
    
    head = &fun1.x;
    
    // fun1 data
    fun1.x = 4;
    fun1.n = &fun2.x;
    
    // fun2 data
    fun2.x = 8;
    fun2.n = nullptr;
    
    while (head != nullptr)
    {
        cout << *head << endl;
        if(*head != *fun1.n)
            head = fun1.n;
        else
        {
            head = fun2.n;
            cout << "End of list\n";
        }
        
    }
    
    return 0;
}