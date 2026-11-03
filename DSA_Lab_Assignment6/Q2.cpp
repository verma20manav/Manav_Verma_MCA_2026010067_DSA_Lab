/*2. Display all the node values in a circular linked list, 
repeating value of head node at the end too.  
Input: 20 → 100 → 40 → 80 → 60, 
Output:  20 100 40 80 60 20. */

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node(int d) : data(d), next(NULL) {}
};

// Insert at the end of the circular list; 'last' points to the last node (last->next = head)
void insertLast(Node *&last, int x) 
{
    Node *n = new Node(x);
    if (!last) 
    { 
        last = n; 
        n->next = n; 
    }
    else 
    { 
        n->next = last->next; 
        last->next = n; 
        last = n; 
    }
}

// Print every node once, then print the head value again to show the list is circular
void display(Node *last) {
    if (!last) 
    { 
        cout << "List is empty\n"; 
        return; 
    }
    Node *head = last->next;
    Node *t = head;
    do {
        cout << t->data << " ";
        t = t->next;
    } while (t != head);
    cout << head->data << endl;                 // head value repeated at the end
}

int main() {
    Node *last = NULL;
    int n, x;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter " << n << " values: ";
    for (int i = 0; i < n; i++) 
    { 
        cin >> x; 
        insertLast(last, x); 
    }

    cout << "Output: ";
    display(last);

    if (last) {                                  // free memory: break the circle first
        Node *t = last->next;
        last->next = NULL;
        while (t) 
        { 
            Node *d = t; 
            t = t->next; 
            delete d; 
        }
    }
    return 0;
}