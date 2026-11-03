/*1. Develop a menu driven program for the following operations on a Singly Linked List. 
(a) Insertion at the beginning. 
(b) Insertion at the end. 
(c) Insertion in between (before or after a node having a specific value, say 'Insert a new Node 35 before/after the Node 30'). 
(d) Deletion from the beginning. 
(e) Deletion from the end. 
(f) Deletion of a specific node, say 'Delete Node 60'). 
(g) Search for a node and display its position from head. 
(h) Display all the node values. */

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node(int d) : data(d), next(NULL) {}
};

class LinkedList {
    Node *head;
public:
    LinkedList() : head(NULL) {}
    ~LinkedList() {
        while (head) 
        { 
            Node *t = head; 
            head = head->next; 
            delete t; 
        }
    }

    // (a) Insertion at the beginning
    void insertBegin(int x) {
        Node *n = new Node(x);
        n->next = head;
        head = n;
        cout << x << " inserted at the beginning\n";
    }

    // (b) Insertion at the end
    void insertEnd(int x) {
        Node *n = new Node(x);
        if (!head) head = n;
        else {
            Node *t = head;
            while (t->next) 
            t = t->next;
            t->next = n;
        }
        cout << x << " inserted at the end\n";
    }

    // (c) Insertion before a node having value 'key'
    void insertBefore(int x, int key) {
        if (!head) 
        { 
            cout << "List is empty\n"; 
            return; 
        }
        if (head->data == key) 
        {                 // key is the first node
            Node *n = new Node(x);
            n->next = head;
            head = n;
            cout << x << " inserted before " << key << endl;
            return;
        }
        Node *t = head;
        while (t->next && t->next->data != key)
        t = t->next;
        if (!t->next) 
        {
            cout << "Node " << key << " not found\n"; 
            return; 
        }
        Node *n = new Node(x);
        n->next = t->next;
        t->next = n;
        cout << x << " inserted before " << key << endl;
    }

    // (c) Insertion after a node having value 'key'
    void insertAfter(int x, int key) {
        Node *t = head;
        while (t && t->data != key) 
        t = t->next;
        if (!t) 
        { 
            cout << "Node " << key << " not found\n"; 
            return; 
        }
        Node *n = new Node(x);
        n->next = t->next;
        t->next = n;
        cout << x << " inserted after " << key << endl;
    }

    // (d) Deletion from the beginning
    void deleteBegin() {
        if (!head) { cout << "List is empty\n"; return; }
        Node *t = head;
        head = head->next;
        cout << t->data << " deleted from the beginning\n";
        delete t;
    }

    // (e) Deletion from the end
    void deleteEnd() {
        if (!head) { cout << "List is empty\n"; return; }
        if (!head->next) {
            cout << head->data << " deleted from the end\n";
            delete head;
            head = NULL;
            return;
        }
        Node *t = head;
        while (t->next->next) 
        t = t->next;       // second last node
        cout << t->next->data << " deleted from the end\n";
        delete t->next;
        t->next = NULL;
    }

    // (f) Deletion of a specific node
    void deleteNode(int key) {
        if (!head) 
        { 
            cout << "List is empty\n"; 
            return; 
        }
        if (head->data == key) 
        {
            Node *t = head;
            head = head->next;
            delete t;
            cout << "Node " << key << " deleted\n";
            return;
        }
        Node *t = head;
        while (t->next && t->next->data != key) 
        t = t->next;
        if (!t->next) 
        { 
            cout << "Node " << key << " not found\n"; 
            return; 
        }
        Node *d = t->next;
        t->next = d->next;
        delete d;
        cout << "Node " << key << " deleted\n";
    }

    // (g) Search a node and display its position from head (1-based)
    void search(int key) {
        int pos = 1;
        for (Node *t = head; t; t = t->next, pos++) 
        {
            if (t->data == key) 
            {
                cout << "Node " << key << " found at position " << pos << " from head\n";
                return;
            }
        }
        cout << "Node " << key << " not found\n";
    }

    // (h) Display all node values
    void display() {
        if (!head) { cout << "List is empty\n"; return; }
        cout << "List: ";
        for (Node *t = head; t; t = t->next) cout << t->data << " -> ";
        cout << "NULL\n";
    }
};

int main() {
    LinkedList list;
    int ch, x, key, opt;
    do {
        cout << "\n--- SINGLY LINKED LIST MENU ---\n";
        cout << "1. Insert at beginning\n2. Insert at end\n3. Insert before/after a node\n";
        cout << "4. Delete from beginning\n5. Delete from end\n6. Delete a specific node\n";
        cout << "7. Search a node\n8. Display all nodes\n9. Exit\n";
        cout << "Enter choice: ";
        if (!(cin >> ch)) 
        break;
        switch (ch) 
        {
            case 1: 
                cout << "Enter value: "; 
                cin >> x; list.insertBegin(x); 
                break;
            case 2: 
                cout << "Enter value: "; 
                cin >> x; list.insertEnd(x); 
                break;
            case 3:
                cout << "Enter new value: "; 
                cin >> x;
                cout << "Enter existing node value: "; 
                cin >> key;
                cout << "1. Before  2. After : "; 
                cin >> opt;
                if (opt == 1) 
                    list.insertBefore(x, key);
                else if (opt == 2) 
                    list.insertAfter(x, key);
                else 
                    cout << "Invalid option\n";
                break;
            case 4: 
                list.deleteBegin(); 
                break;
            case 5: 
                list.deleteEnd(); 
                break;
            case 6: 
                cout << "Enter value to delete: "; 
                cin >> key; 
                list.deleteNode(key); 
                break;
            case 7: 
                cout << "Enter value to search: "; 
                cin >> key; 
                list.search(key); 
                break;
            case 8: 
                list.display(); 
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