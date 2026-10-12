#include <iostream>
#include <cstdlib>
using namespace std;

struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *start = NULL;
    struct node *ptr;
    struct node *newnode;
    int n, value;

    cout << "no of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Insert Node " << i + 1 << " data: ";
        cin >> value;

        newnode = (struct node*)malloc(sizeof(struct node));

        if (newnode == NULL) {
            cout << "Memory allocation failed!";
            return 1;
        }

        newnode->data = value;
        newnode->next = NULL;

        if (start == NULL) {
            start = newnode;
        } else {
            ptr = start;

            while (ptr->next != NULL) {
                ptr = ptr->next;
            }

            ptr->next = newnode;
        }
    }

    cout << "linked list is ";
    ptr = start;

    while (ptr != NULL) {
        cout << ptr->data << "->";
        ptr = ptr->next;
    }

    cout << "NULL";

    cout << "\nReleasing memories...\n";

    ptr = start;

    while (ptr != NULL) {
        struct node *nextnode = ptr->next;
        free(ptr);
        ptr = nextnode;
    }

    start = NULL;

    cout << "All nodes freed";

    return 0;
}
