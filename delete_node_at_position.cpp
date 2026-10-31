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

void deleteAtPosition()
{
    if (start == nullptr)
    {
        cout << "Linked List is empty!" << endl;
        return;
    }

    int position;

    cout << "Enter position to delete: ";
    cin >> position;

    if (position < 1)
    {
        cout << "Invalid position!" << endl;
        return;
    }

    if (position == 1)
    {
        node* temp = start;
        start = start->next;
        delete temp;
        return;
    }

    node* ptr = start;

    for (int i = 1; i < position - 1 && ptr != nullptr; i++)
    {
        ptr = ptr->next;
    }

    if (ptr == nullptr || ptr->next == nullptr)
    {
        cout << "Position does not exist!" << endl;
        return;
    }

    node* temp = ptr->next;
    ptr->next = temp->next;
    delete temp;
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

    deleteAtPosition();

    cout << "\nLinked List after deletion: ";
    display();

    freeMemory();

    cout << "Memory freed successfully." << endl;

    return 0;
}
