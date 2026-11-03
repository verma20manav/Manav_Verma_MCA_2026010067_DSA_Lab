/*2) Develop a menu driven program demonstrating the following operations on Circular Queues:
enqueue(), dequeue(), isEmpty(), isFull(), display(), and peek()*/

#include <iostream>
using namespace std;

class CircularQueue {
    static const int MAX = 5;
    int arr[MAX];
    int front, rear;
public:
    CircularQueue() : front(-1), rear(-1) {}

    bool isEmpty() { return front == -1; }
    bool isFull()  { return (rear + 1) % MAX == front; }

    void enqueue(int x) {
        if (isFull()) 
        { 
            cout << "Queue Overflow (queue is full)\n"; 
            return; }
        if (isEmpty()) 
            front = rear = 0;
        else 
            rear = (rear + 1) % MAX;
            arr[rear] = x;
            cout << x << " enqueued\n";
    }

    void dequeue() {
        if (isEmpty()) 
        { 
            cout << "Queue Underflow (queue is empty)\n"; 
            return; }
            cout << arr[front] << " dequeued\n";
        if (front == rear)
            front = rear = -1;
        else 
            front = (front + 1) % MAX;
    }

    void peek() {
        if (isEmpty())
            cout << "Queue is empty\n";
        else 
            cout << "Front element: " << arr[front] << endl;
    }

    void display() {
        if (isEmpty()) 
        { 
            cout << "Queue is empty\n"; 
            return; }
        cout << "Queue: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) 
            break;
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q;
    int ch, x;
    do {
        cout << "\n--- CIRCULAR QUEUE MENU ---\n";
        cout << "1.Enqueue 2.Dequeue 3.isEmpty 4.isFull 5.Display 6.Peek 7.Exit\n";
        cout << "Enter choice: ";
        if (!(cin >> ch)) 
        break;
        switch (ch) {
            case 1: 
                cout << "Enter value: "; 
                cin >> x; q.enqueue(x); 
                break;
            case 2: 
                q.dequeue(); 
                break;
            case 3: 
                cout << (q.isEmpty() ? "Queue is empty\n" : "Queue is not empty\n"); 
                break;
            case 4: 
                cout << (q.isFull() ? "Queue is full\n" : "Queue is not full\n"); 
                break;
            case 5: 
                q.display(); 
                break;
            case 6: 
                q.peek(); 
                break;
            case 7: 
                cout << "Exiting...\n"; 
                break;
            default: 
                cout << "Invalid choice\n";
        }
    } while (ch != 7);
    return 0;
}