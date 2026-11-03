/*3. Write a program to find size of 
i. Doubly Linked List.  
ii. Circular Linked List. */

#include <iostream>
using namespace std;

/* ---------------- (i) Doubly Linked List ---------------- */
struct DNode {
    int data;
    DNode *prev, *next;
    DNode(int d) : data(d), prev(NULL), next(NULL) {}
};

void insertEndDLL(DNode *&head, int x) {
    DNode *n = new DNode(x);
    if (!head) 
    { 
        head = n; 
        return; 
    }
    DNode *t = head;
    while (t->next) 
    t = t->next;
    t->next = n;
    n->prev = t;
}

// Traverse from head until NULL, counting nodes
int sizeDLL(DNode *head) {
    int count = 0;
    for (DNode *t = head; t; t = t->next) 
        count++;
    return count;
}

/* ---------------- (ii) Circular Linked List ---------------- */
struct CNode {
    int data;
    CNode *next;
    CNode(int d) : data(d), next(NULL) {}
};

// 'last' points to the last node; last->next is the head
void insertEndCLL(CNode *&last, int x) 
{
    CNode *n = new CNode(x);
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

// Traverse until we come back to the head (there is no NULL to stop at)
int sizeCLL(CNode *last) 
{
    if (!last) return 0;
    int count = 0;
    CNode *head = last->next, *t = head;
    do {
        count++;
        t = t->next;
    } while (t != head);
    return count;
}

int main() {
    int n, x;

    // (i) Doubly linked list
    DNode *dhead = NULL;
    cout << "Doubly Linked List - enter number of nodes: ";
    cin >> n;
    cout << "Enter " << n << " values: ";
    for (int i = 0; i < n; i++) 
    { 
        cin >> x; 
        insertEndDLL(dhead, x); 
    }
    cout << "Size of Doubly Linked List = " << sizeDLL(dhead) << endl;

    // (ii) Circular linked list
    CNode *clast = NULL;
    cout << "\nCircular Linked List - enter number of nodes: ";
    cin >> n;
    cout << "Enter " << n << " values: ";
    for (int i = 0; i < n; i++) 
    { 
        cin >> x; 
        insertEndCLL(clast, x); 
    }
    cout << "Size of Circular Linked List = " << sizeCLL(clast) << endl;

    // free memory
    while (dhead) 
    { 
        DNode *t = dhead; 
        dhead = dhead->next; 
        delete t; }
    if (clast) {
        CNode *t = clast->next;
        clast->next = NULL;                       // break the circle
        while (t) 
        { 
            CNode *d = t; 
            t = t->next; 
            delete d; 
        }
    }
    return 0;
}