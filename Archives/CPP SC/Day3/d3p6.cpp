#include <iostream>
using namespace std;

class Node; // Forward declaration

class List {
    Node* head; // Head of the list
    Node* tail; // Tail of the list

public:
    List() : head(NULL), tail(NULL) {}
    void display();
    void append(Node* p);
};

class Node {
    int info;      // Data of the node
    Node* next;    // Pointer to next node

public:
    Node(int i) : info(i), next(NULL) {}
    friend class List; // List class is made a friend to the Node class
};

void List::display() {
    Node* ptr = head;
    while (ptr) {
        cout << ptr->info << " ";  // Print the data of the current node
        ptr = ptr->next;           // Move to the next node
    }
    cout << endl;
}

void List::append(Node* p) {
    if (!head) {
        // If the list is empty, make the new node both the head and tail
        head = tail = p;
    } else {
        // If the list is not empty, append the new node at the end and update the tail
        tail->next = p;
        tail = tail->next;
    }
}

int main() {
    List l;                 // Step 1: Initialize an empty list
    Node n1(1), n2(2), n3(3);  // Step 2: Create a few nodes

    l.append(&n1);          // Step 3: Add nodes to the list
    l.append(&n2);
    l.append(&n3);

    l.display();            // Step 4: Display the list

    return 0;
}
