/*2. Write a program to count the number of occurrences of a given key in a singly linked list and then delete all the occurrences. 
 Input: Linked List :  1->2->1->2->1->3->1 , key:  1                                                                   
  Output: Count: 4 ,  Updated Linked List: 2->2->3.*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node(int d) : data(d), next(NULL) {}
};

// Insert at the end (used to build the list from input)
void insertEnd(Node *&head, int x) {
    Node *n = new Node(x);
    if (!head) 
    { 
        head = n; 
        return; 
    }
    Node *t = head;
    while (t->next) t = t->next;
    t->next = n;
}

void display(Node *head) {
    if (!head) 
    { 
        cout << "List is empty\n"; 
        return; }
    for (Node *t = head; t; t = t->next) 
    {
        cout << t->data;
        if (t->next) cout << "->";
    }
    cout << endl;
}

// Counts the occurrences of key and deletes every such node; returns the count
int countAndDelete(Node *&head, int key) {
    int count = 0;

    // delete matching nodes at the head
    while (head && head->data == key) {
        Node *t = head;
        head = head->next;
        delete t;
        count++;
    }

    // delete matching nodes in the rest of the list
    Node *curr = head;
    while (curr && curr->next) {
        if (curr->next->data == key) {
            Node *d = curr->next;
            curr->next = d->next;      // unlink
            delete d;
            count++;                   // stay on curr: new next may also match
        } else {
            curr = curr->next;
        }
    }
    return count;
}

int main() {
    Node *head = NULL;
    int n, x, key;

    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter " << n << " values: ";
    for (int i = 0; i < n; i++) 
    { 
        cin >> x; 
        insertEnd(head, x); 
    }
    cout << "Enter key: ";
    cin >> key;

    cout << "Linked List: ";
    display(head);
    int count = countAndDelete(head, key);
    cout << "Count: " << count << endl;
    cout << "Updated Linked List: "; 
    display(head);

    while (head) 
    {
        Node *t = head; 
        head = head->next; 
        delete t; 
    }   // free memory
    return 0;
}