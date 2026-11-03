/*
3) Write a program interleave the first half of the queue with second half.
Sample I/P: 4 7 11 20 5 9 Sample O/P: 4 20 7 5 11 9
*/

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

void interleave(Queue &q) {
    int n = q.size(), half = n / 2;
    Queue firstHalf;
    for (int i = 0; i < half; i++) 
    firstHalf.enqueue(q.dequeue());   // move 1st half
    while (!firstHalf.isEmpty()) {
        q.enqueue(firstHalf.dequeue());   // element from first half
        q.enqueue(q.dequeue());           // element from second half
    }
    if (n % 2 == 1) q.enqueue(q.dequeue());   // odd n: leftover middle element
}

int main() {
    Queue q;
    int n, x;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) { cin >> x; q.enqueue(x); }
    cout << "Original   : "; q.display();
    interleave(q);
    cout << "Interleaved: "; q.display();
    return 0;
}