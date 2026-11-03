/*3. Write a program to find the middle of a linked list. 
Input: 1->2->3->4->5 
Output: 3 */

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
        return; 
    }
    Node *t = head;
    while (t->next) 
    t = t->next;
    t->next = n;
}

void display(Node *head) 
{
    for (Node *t = head; t; t = t->next) 
    {
        cout << t->data;
        if (t->next) cout << "->";
    }
    cout << endl;
}

// slow moves 1 step, fast moves 2 steps; when fast reaches the end, slow is at the middle.
// For an even number of nodes this returns the second of the two middle nodes.
Node *findMiddle(Node *head) {
    Node *slow = head, *fast = head;
    while (fast && fast->next) 
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main() {
    Node *head = NULL;
    int n, x;
    cout << "Enter number of nodes: ";
    cin >> n;
    if (n <= 0) 
    { 
        cout << "List is empty\n"; 
        return 0; 
    }
    cout << "Enter " << n << " values: ";
    for (int i = 0; i < n; i++) 
    { 
        cin >> x; 
        insertEnd(head, x); 
    }

    cout << "Linked List: "; 
    display(head);
    cout << "Middle: " << findMiddle(head)->data << endl;

    while (head) 
    { 
        Node *t = head; 
        head = head->next; 
        delete t; 
    }   // free memory
    return 0;
}