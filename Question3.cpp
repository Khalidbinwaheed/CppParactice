#include <iostream>
#include <queue>

int getQueueSize(std::queue<int> q) {
    int size = 0;
    std::queue<int> aux;

    // Count elements and transfer them to the auxiliary queue
    while (!q.empty()) {
        aux.push(q.front());
        q.pop();
        size++;
    }

    // Restore the original queue
    while (!aux.empty()) {
        q.push(aux.front());
        aux.pop();
    }

    return size;
}

int main() {
    std::queue<int> q;
    
    // Add some elements to the queue
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    // Find the size of the queue
    std::cout << "Size of the queue: " << getQueueSize(q) << std::endl;

    return 0;
}
