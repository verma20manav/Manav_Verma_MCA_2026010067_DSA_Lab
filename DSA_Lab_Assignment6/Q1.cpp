/*1. Develop a menu driven program for the following operations of on a Circular as well as a Doubly Linked List. 
(a) Insertion anywhere in the linked list (As a first node, as a last node, and after/before a specific node). 
(b) Deletion of a specific node, say 'Delete Node 60'. That mean the node to be deleted may appear as a head node, last node or a node in between. 
(c) Search for a node. */

// Menu driven program on a Doubly Linked List
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *prev, *next;
    Node(int d) : data(d), prev(NULL), next(NULL) {}
};

class DoublyList {
    Node *head, *tail;

    Node *find(int key) {
        Node *t = head;
        while (t && t->data != key) t = t->next;
        return t;
    }
public:
    DoublyList() : head(NULL), tail(NULL) {}
    ~DoublyList() {
        while (head) { Node *t = head; head = head->next; delete t; }
    }

    // (a) Insert as the first node
    void insertFirst(int x) {
        Node *n = new Node(x);
        n->next = head;
        if (head) head->prev = n; else tail = n;
        head = n;
        cout << x << " inserted as the first node\n";
    }

    // (a) Insert as the last node
    void insertLast(int x) {
        Node *n = new Node(x);
        n->prev = tail;
        if (tail) tail->next = n; else head = n;
        tail = n;
        cout << x << " inserted as the last node\n";
    }

    // (a) Insert after a specific node
    void insertAfter(int x, int key) {
        Node *t = find(key);
        if (!t) { cout << "Node " << key << " not found\n"; return; }
        Node *n = new Node(x);
        n->prev = t;
        n->next = t->next;
        if (t->next) t->next->prev = n; else tail = n;
        t->next = n;
        cout << x << " inserted after " << key << endl;
    }

    // (a) Insert before a specific node
    void insertBefore(int x, int key) {
        Node *t = find(key);
        if (!t) { cout << "Node " << key << " not found\n"; return; }
        Node *n = new Node(x);
        n->next = t;
        n->prev = t->prev;
        if (t->prev) t->prev->next = n; else head = n;
        t->prev = n;
        cout << x << " inserted before " << key << endl;
    }

    // (b) Delete a specific node (head, last or in between)
    void deleteNode(int key) {
        Node *t = find(key);
        if (!t) { cout << "Node " << key << " not found\n"; return; }
        if (t->prev) t->prev->next = t->next; else head = t->next;
        if (t->next) t->next->prev = t->prev; else tail = t->prev;
        delete t;
        cout << "Node " << key << " deleted\n";
    }

    // (c) Search a node (position from head, 1-based)
    void search(int key) {
        int pos = 1;
        for (Node *t = head; t; t = t->next, pos++) {
            if (t->data == key) {
                cout << "Node " << key << " found at position " << pos << endl;
                return;
            }
        }
        cout << "Node " << key << " not found\n";
    }

    void displayForward() {
        if (!head) { cout << "List is empty\n"; return; }
        cout << "Forward : NULL <-> ";
        for (Node *t = head; t; t = t->next) cout << t->data << " <-> ";
        cout << "NULL\n";
    }

    void displayBackward() {
        if (!tail) { cout << "List is empty\n"; return; }
        cout << "Backward: NULL <-> ";
        for (Node *t = tail; t; t = t->prev) cout << t->data << " <-> ";
        cout << "NULL\n";
    }
};

int main() {
    DoublyList list;
    int ch, x, key;
    do {
        cout << "\n--- DOUBLY LINKED LIST MENU ---\n";
        cout << "1. Insert as first node\n2. Insert as last node\n";
        cout << "3. Insert after a node\n4. Insert before a node\n";
        cout << "5. Delete a specific node\n6. Search a node\n";
        cout << "7. Display forward\n8. Display backward\n9. Exit\n";
        cout << "Enter choice: ";
        if (!(cin >> ch)) 
        break;
        switch (ch) {
            case 1: 
                cout << "Enter value: "; 
                cin >> x; 
                list.insertFirst(x); 
                break;
            case 2: 
                cout << "Enter value: "; 
                cin >> x; 
                list.insertLast(x); 
                break;
            case 3: 
                cout << "Enter new value: "; 
                cin >> x;
                cout << "Insert after node: "; 
                cin >> key; 
                list.insertAfter(x, key); 
                break;
            case 4: 
                cout << "Enter new value: "; 
                cin >> x;
                cout << "Insert before node: "; 
                cin >> key; 
                list.insertBefore(x, key); 
                break;
            case 5: 
                cout << "Enter value to delete: "; 
                cin >> key; 
                list.deleteNode(key); 
                break;
            case 6: 
                cout << "Enter value to search: "; 
                cin >> key; 
                list.search(key); 
                break;
            case 7: 
                list.displayForward(); 
                break;
            case 8: 
                list.displayBackward(); 
                break;
            case 9: 
                cout << "Exiting...\n"; 
                break;
            default: 
                cout << "Invalid choice\n";
        }
    } while (ch != 9);
    return 0;
}