// Q5: Stack using (a) two queues and (b) one queue
#include <iostream>
using namespace std;
const int SIZE = 1000;

// Circular-array based integer queue (basic ADT used below)
class Queue {
    int a[SIZE], f, cnt;
public:
    Queue() : f(0), cnt(0) {}
    bool isEmpty() { return cnt == 0; }
    bool isFull()  { return cnt == SIZE; }
    int  size()    { return cnt; }
    void enqueue(int x) { a[(f + cnt) % SIZE] = x; cnt++; }
    int  dequeue() { int x = a[f]; f = (f + 1) % SIZE; cnt--; return x; }
    int  peek()    { return a[f]; }
    void display() { for (int i = 0; i < cnt; i++) cout << a[(f + i) % SIZE] << " "; cout << endl; }
};

// (a) Stack using two queues (push is costly)
class StackTwoQueues {
    Queue qa, qb;
    Queue *q1, *q2;
public:
    StackTwoQueues() : q1(&qa), q2(&qb) {}
    bool isEmpty() { return q1->isEmpty(); }
    void push(int x) {
        q2->enqueue(x);
        while (!q1->isEmpty()) q2->enqueue(q1->dequeue());
        swap(q1, q2);                          // q1 always holds the stack (top at front)
    }
    int pop()  { return q1->dequeue(); }
    int top()  { return q1->peek(); }
    void display() { cout << "Stack (top -> bottom): "; q1->display(); }
};

// (b) Stack using one queue (push is costly)
class StackOneQueue {
    Queue q;
public:
    bool isEmpty() { return q.isEmpty(); }
    void push(int x) {
        int n = q.size();
        q.enqueue(x);
        for (int i = 0; i < n; i++) q.enqueue(q.dequeue());   // rotate: x comes to front
    }
    int pop()  { return q.dequeue(); }
    int top()  { return q.peek(); }
    void display() { cout << "Stack (top -> bottom): "; q.display(); }
};

template <class S>
void run(S &s) {
    int ch, x;
    do {
        cout << "\n1.Push 2.Pop 3.Top 4.Display 5.Exit\nEnter choice: ";
        if (!(cin >> ch)) break;
        switch (ch) {
            case 1: 
                cout << "Enter value: "; 
                cin >> x; 
                s.push(x); 
                break;
            case 2: 
                if (s.isEmpty()) 
                    cout << "Stack Underflow\n";
                else 
                    cout << "Popped: " << s.pop() << endl;
                    break;
            case 3: 
                if (s.isEmpty()) 
                    cout << "Stack is empty\n";
                else 
                    cout << "Top: " << s.top() << endl;
                    break;
            case 4: 
                if (s.isEmpty()) 
                    cout << "Stack is empty\n"; 
                else 
                    s.display(); break;
            case 5: 
                break;
            default: 
                cout << "Invalid choice\n";
        }
    } while (ch != 5);
}

int main() {
    int mode;
    cout << "1. Stack using two queues\n2. Stack using one queue\nChoose: ";
    cin >> mode;
    if (mode == 1) 
    { 
        StackTwoQueues s; 
        run(s); 
    }
    else           
    { 
        StackOneQueue  s; 
        run(s); 
    }
    return 0;
}