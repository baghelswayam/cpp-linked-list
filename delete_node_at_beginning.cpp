#include <iostream>
using namespace std;

struct node
{
    int data;
    node* next;
};

node* start = nullptr;
node* ptr = nullptr;

void createnode()
{
    node* newnode = new node;

    int val;
    cout << "Enter data: ";
    cin >> val;

    newnode->data = val;
    newnode->next = nullptr;

    if (start == nullptr)
    {
        start = newnode;
    }
    else
    {
        ptr = start;

        while (ptr->next != nullptr)
        {
            ptr = ptr->next;
        }

        ptr->next = newnode;
    }
}

void display()
{
    ptr = start;

    while (ptr != nullptr)
    {
        cout << ptr->data << " -> ";
        ptr = ptr->next;
    }

    cout << "NULL" << endl;
}

void deletebeg()
{
    if (start == nullptr)
    {
        cout << "Linked List is empty!" << endl;
        return;
    }

    node* temp = start;
    start = start->next;

    delete temp;
}

void freeMemory()
{
    while (start != nullptr)
    {
        node* temp = start;
        start = start->next;
        delete temp;
    }

    ptr = nullptr;
}

int main()
{
    int n;

    cout << "Number of nodes: ";
    cin >> n;

    if (n < 0)
    {
        cout << "Number of nodes cannot be negative." << endl;
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        createnode();
    }

    cout << "\nExisting linked list is: ";
    display();

    cout << "\nAfter deletion from beginning: ";
    deletebeg();
    display();

    freeMemory();

    cout << "\nMemory freed successfully." << endl;

    return 0;
}

