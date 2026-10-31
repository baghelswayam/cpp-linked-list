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

void deleteNodeAtEnd()
{
    if (start == nullptr)
    {
        cout << "Linked List is empty." << endl;
        return;
    }

    if (start->next == nullptr)
    {
        delete start;
        start = nullptr;
        return;
    }

    node* ptr = start;

    while (ptr->next->next != nullptr)
    {
        ptr = ptr->next;
    }

    delete ptr->next;
    ptr->next = nullptr;
}

int main()
{
    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    if (n < 0)
    {
        cout << "Invalid number of nodes." << endl;
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        createNode();
    }

    cout << "\nOriginal Linked List: ";
    display();

    deleteNodeAtEnd();

    cout << "After deleting last node: ";
    display();

    // Free remaining memory
    while (start != nullptr)
    {
        node* temp = start;
        start = start->next;
        delete temp;
    }

    cout << "Memory freed successfully." << endl;

    return 0;
}

