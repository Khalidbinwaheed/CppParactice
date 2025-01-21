#include <iostream>
#define SIZE 5

class Queue {
private:
    int items[SIZE];
    int front, rear;
public:
    Queue() {
        front = -1;
        rear = -1;
    }

    // Check if the queue is full
    bool isFull() {
        return (rear == SIZE - 1);
    }

    // Check if the queue is empty
    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    // Add an element to the queue
    void enqueue(int element) {
        if (isFull()) {
            std::cout << "Queue is full" << std::endl;
            return;
        }
        if (front == -1) front = 0;
        items[++rear] = element;
        std::cout << "Enqueued: " << element << std::endl;
    }

    // Remove an element from the queue
    int dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty" << std::endl;
            return -1;
        }
        int element = items[front++];
        if (front > rear) {
            front = rear = -1;
        }
        return element;
    }
};

int main() {
    Queue q;

    // Enqueue elements
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    // Dequeue and print elements
    std::cout << "Dequeued elements: ";
    while (!q.isEmpty()) {
        std::cout << q.dequeue() << " ";
    }
    std::cout << std::endl;

    return 0;
}
