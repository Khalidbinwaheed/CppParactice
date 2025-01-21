#include <iostream>
#define SIZE 5

class CircularQueue {
private:
    int items[SIZE];
    int front, rear;
public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    // Check if the queue is full
    bool isFull() {
        if ((front == 0 && rear == SIZE - 1) || (rear == (front - 1) % (SIZE - 1))) {
            return true;
        }
        return false;
    }

    // Check if the queue is empty
    bool isEmpty() {
        if (front == -1) {
            return true;
        }
        return false;
    }

    // Add an element to the queue
    void enqueue(int element) {
        if (isFull()) {
            std::cout << "Queue is full" << std::endl;
            return;
        }

        if (front == -1) { // First element insertion
            front = 0;
            rear = 0;
        } else if (rear == SIZE - 1 && front != 0) {
            rear = 0;
        } else {
            rear++;
        }
        items[rear] = element;
    }

    // Remove an element from the queue
    int dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty" << std::endl;
            return -1;
        }

        int element = items[front];
        if (front == rear) { // Queue has only one element
            front = -1;
            rear = -1;
        } else if (front == SIZE - 1) {
            front = 0;
        } else {
            front++;
        }
        return element;
    }

    // Display the queue elements
    void display() {
        if (isEmpty()) {
            std::cout << "Queue is empty" << std::endl;
            return;
        }

        std::cout << "Queue elements are: ";
        if (rear >= front) {
            for (int i = front; i <= rear; i++) {
                std::cout << items[i] << " ";
            }
        } else {
            for (int i = front; i < SIZE; i++) {
                std::cout << items[i] << " ";
            }
            for (int i = 0; i <= rear; i++) {
                std::cout << items[i] << " ";
            }
        }
        std::cout << std::endl;
    }
};

int main() {
    CircularQueue cq;

    // Enqueue 5 elements
    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.enqueue(40);
    cq.enqueue(50);

    // Display the queue
    cq.display();

    // Dequeue and print elements
    std::cout << "Dequeued elements: ";
    std::cout << cq.dequeue() << " ";
    std::cout << cq.dequeue() << " ";
    std::cout << cq.dequeue() << " ";
    std::cout << cq.dequeue() << " ";
    std::cout << cq.dequeue() << std::endl;

    return 0;
}
