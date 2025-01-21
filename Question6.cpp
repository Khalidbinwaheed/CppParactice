#include <iostream>
#define MAX 1000  // Maximum size of the deque

class Deque {
private:
    int arr[MAX];
    int front;
    int rear;
    int size;

public:
    Deque(int size) {
        front = -1;
        rear = 0;
        this->size = size;
    }

    // Check if the deque is full
    bool isFull() {
        return ((front == 0 && rear == size - 1) || front == rear + 1);
    }

    // Check if the deque is empty
    bool isEmpty() {
        return (front == -1);
    }

    // Insert at the front end
    void insertFront(int key) {
        if (isFull()) {
            std::cout << "Overflow\n" << std::endl;
            return;
        }

        // If the deque is initially empty
        if (front == -1) {
            front = 0;
            rear = 0;
        } else if (front == 0) {
            front = size - 1;
        } else {
            front = front - 1;
        }

        arr[front] = key;
    }

    // Delete from the rear end
    void deleteRear() {
        if (isEmpty()) {
            std::cout << "Underflow\n" << std::endl;
            return;
        }

        // If the deque has only one element
        if (front == rear) {
            front = -1;
            rear = -1;
        } else if (rear == 0) {
            rear = size - 1;
        } else {
            rear = rear - 1;
        }
    }

    // Get the front element
    int getFront() {
        if (isEmpty()) {
            std::cout << "Underflow\n" << std::endl;
            return -1;
        }
        return arr[front];
    }

    // Get the rear element
    int getRear() {
        if (isEmpty() || rear < 0) {
            std::cout << "Underflow\n" << std::endl;
            return -1;
        }
        return arr[rear];
    }
};

int main() {
    Deque dq(5);

    std::cout << "Insert element at front end: 5 \n";
    dq.insertFront(5);

    std::cout << "Get rear element: " << dq.getRear() << std::endl;

    std::cout << "Insert element at front end: 10 \n";
    dq.insertFront(10);

    std::cout << "Get front element: " << dq.getFront() << std::endl;

    std::cout << "Delete rear element\n";
    dq.deleteRear();

    std::cout << "Get rear element: " << dq.getRear() << std::endl;

    return 0;
}
