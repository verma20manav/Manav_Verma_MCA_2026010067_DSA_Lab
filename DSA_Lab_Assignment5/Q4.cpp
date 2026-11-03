/*4. Write a program to reverse a linked list. 
Input: 1->2->3->4->NULL 
Output: 4->3->2->1->NULL */

// Reverse a singly linked list (iterative, by reversing the links)
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node(int d) : data(d), next(NULL) {}
};

void insertEnd(Node *&head, int x) {
    Node *n = new Node(x);
    if (!head) 
    { 
        head = n; 
        return; }
    Node *t = head;
    while (t->next) 
    t = t->next;
    t->next = n;
}

void display(Node *head) 
{
    for (Node *t = head; t; t = t->next) 
    cout << t->data << "->";
    cout << "NULL\n";
}

// Uses three pointers: prev, curr, nxt
Node *reverse(Node *head) {
    Node *prev = NULL, *curr = head, *nxt = NULL;
    while (curr) {
        nxt = curr->next;      // save the next node
        curr->next = prev;     // reverse the link
        prev = curr;           // move prev forward
        curr = nxt;            // move curr forward
    }
    return prev;               // prev is the new head
}

int main() {
    Node *head = NULL;
    int n, x;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter " << n << " values: ";
    for (int i = 0; i < n; i++) 
    { 
        cin >> x; 
        insertEnd(head, x); 
    }

    cout << "Original: "; 
    display(head);
    head = reverse(head);
    cout << "Reversed: "; 
    display(head);

    while (head) 
    { 
        Node *t = head; 
        head = head->next; 
        delete t; 
    }
    return 0;
}