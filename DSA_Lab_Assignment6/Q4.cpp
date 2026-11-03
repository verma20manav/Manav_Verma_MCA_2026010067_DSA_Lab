/*4. Write a program to check if a doubly linked list of characters is palindrome or not. */

#include <iostream>
using namespace std;

struct Node {
    char data;
    Node *prev, *next;
    Node(char d) : data(d), prev(NULL), next(NULL) {}
};

// Insert at the end; keeps both head and tail up to date
void insertEnd(Node *&head, Node *&tail, char c) {
    Node *n = new Node(c);
    if (!head) { head = tail = n; return; }
    tail->next = n;
    n->prev = tail;
    tail = n;
}

void display(Node *head) {
    cout << "NULL <-> ";
    for (Node *t = head; t; t = t->next) cout << t->data << " <-> ";
    cout << "NULL\n";
}

// Two pointers: one from head moving forward, one from tail moving backward
bool isPalindrome(Node *head, Node *tail) {
    Node *left = head, *right = tail;
    while (left && right && left != right && right->next != left) {
        if (left->data != right->data) return false;
        left = left->next;
        right = right->prev;
    }
    return true;
}

int main() {
    Node *head = NULL, *tail = NULL;
    int n;
    char c;

    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter " << n << " characters: ";
    for (int i = 0; i < n; i++) { cin >> c; insertEnd(head, tail, c); }

    cout << "List: "; display(head);
    cout << (isPalindrome(head, tail) ? "True" : "False") << endl;

    while (head) { Node *t = head; head = head->next; delete t; }
    return 0;
}