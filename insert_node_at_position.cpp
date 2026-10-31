#include <iostream>
using namespace std;

struct node
{
    int data;
    node* next;
};

node* start = nullptr;

void createNode()
{
    node* newnode = new node;

    cout << "Enter data: ";
    cin >> newnode->data;

    newnode->next = nullptr;

    if (start == nullptr)
    {
        start = newnode;
    }
    else
    {
        node* ptr = start;

        while (ptr->next != nullptr)
        {
            ptr = ptr->next;
        }

        ptr->next = newnode;
    }
}

void insertAtPosition()
{
    int data, position;

    cout << "Enter data to insert: ";
    cin >> data;

    cout << "Enter position: ";
    cin >> position;

    if (position < 1)
    {
        cout << "Invalid position!" << endl;
        return;
    }

    node* newnode = new node;
    newnode->data = data;
    newnode->next = nullptr;

    if (position == 1)
    {
        newnode->next = start;
        start = newnode;
        return;
    }

    node* ptr = start;

    for (int i = 1; i < position - 1 && ptr != nullptr; i++)
    {
        ptr = ptr->next;
    }

    if (ptr == nullptr)
    {
        cout << "Invalid position!" << endl;
        delete newnode;
        return;
    }

    newnode->next = ptr->next;
    ptr->next = newnode;
}

void display()
{
    node* ptr = start;

    while (ptr != nullptr)
    {
        cout << ptr->data << " -> ";
        ptr = ptr->next;
    }

    cout << "NULL" << endl;
}

void freeMemory()
{
    while (start != nullptr)
    {
        node* temp = start;
        start = start->next;
        delete temp;
    }
}

int main()
{
    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    if (n < 0)
    {
        cout << "Invalid number of nodes!" << endl;
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        createNode();
    }

    cout << "\nOriginal Linked List: ";
    display();

    insertAtPosition();

    cout << "\nAfter insertion: ";
    display();

    freeMemory();

    return 0;
}
