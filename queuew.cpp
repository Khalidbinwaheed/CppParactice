#include <iostream>
using namespace std;

#define MAX 100

class Queue {
    int arr[MAX];
    int front, rear;

public:
    Queue() : front(-1), rear(-1) {}

    bool isEmpty() {
        return (front == -1);
    }

    bool isFull() {
        return (rear == MAX - 1);
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue is full" << endl;
            return;
        }
        if (isEmpty())
            front = 0;
        arr[++rear] = x;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int x = arr[front];
        if (front == rear)
            front = rear = -1; // Reset queue
        else
            front++;
        return x;
    }

    int frontElement() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }
};

int main() {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout << "Front element is: " << q.frontElement() << endl;
    cout << "Dequeued element: " << q.dequeue() << endl;
    cout << "Front element after dequeue: " << q.frontElement() << endl;

    return 0;
}
