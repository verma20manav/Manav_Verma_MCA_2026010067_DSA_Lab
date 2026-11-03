/*4) Write a program to find first non-repeating character in a string using Queue.
Sample I/P: a a b c Sample O/P: a -1 b b
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
#include <string>
int main() {
    string str;
    int freq[256] = {0};
    Queue q;                                   // stores characters (as ints)
    cout << "Enter characters separated by spaces (e.g. a a b c): ";
    getline(cin, str);

    cout << "Output: ";
    for (char c : str) 
    {
        if (c == ' ') continue;
        unsigned char u = (unsigned char)c;
        freq[u]++;
        if (freq[u] == 1) 
        q.enqueue(u);                        // new character
        while (!q.isEmpty() && freq[q.peek()] > 1) 
        q.dequeue(); // drop repeated ones
        if (q.isEmpty()) 
        cout << "-1 ";
        else 
        cout << (char)q.peek() << " ";
    }
    cout << endl;
    return 0;
}