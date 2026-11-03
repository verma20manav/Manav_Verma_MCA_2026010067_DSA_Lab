/*5. Write a program to check if a linked list is Circular Linked List or not. */

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node(int d) : data(d), next(NULL) {}
};

// Insert at the end (plain singly linked insertion; last->next stays NULL)
void insertEnd(Node *&head, int x) {
    Node *n = new Node(x);
    if (!head) { head = n; return; }
    Node *t = head;
    while (t->next) t = t->next;
    t->next = n;
}

// Walk from the head: reaching NULL means NOT circular, coming back to head means circular
bool isCircular(Node *head) {
    if (!head) return false;                  // empty list: treated as not circular
    Node *t = head->next;
    while (t && t != head) t = t->next;
    return t == head;
}

void display(Node *head, bool circular) {
    Node *t = head;
    while (t) {
        cout << t->data;
        t = t->next;
        if (circular && t == head) break;     // stop after one full round
        if (t) cout << "->";
    }
    if (circular) cout << "->(back to " << head->data << ")";
    cout << endl;
}

int main() {
    Node *head = NULL;
    int n, x, link;

    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter " << n << " values: ";
    for (int i = 0; i < n; i++) { cin >> x; insertEnd(head, x); }

    if (head) {
        cout << "Should the last node point back to the head? (1 = yes, 0 = no): ";
        cin >> link;
        if (link == 1) {                      // make the list circular
            Node *t = head;
            while (t->next) t = t->next;
            t->next = head;
        }
    }

    cout << "LinkedList: "; display(head, isCircular(head));
    cout << (isCircular(head) ? "True" : "False") << endl;

    // free memory (break the circle first, if there is one)
    if (isCircular(head)) {
        Node *last = head;
        while (last->next != head) last = last->next;
        last->next = NULL;
    }
    while (head) { Node *d = head; head = head->next; delete d; }
    return 0;
}