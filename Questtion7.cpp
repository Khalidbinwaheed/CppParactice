#include <iostream>
#include <queue>
#include <stack>

// Function to reverse the elements of a queue
void reverseQueue(std::queue<int>& q) {
    std::stack<int> s;
    
    // Transfer elements from the queue to the stack
    while (!q.empty()) {
        s.push(q.front());
        q.pop();
    }
    
    // Transfer elements back to the queue from the stack
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
}

int main() {
    std::queue<int> q;
    
    // Add some elements to the queue
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    std::cout << "Original queue: ";
    std::queue<int> temp = q;  // To print the original queue
    while (!temp.empty()) {
        std::cout << temp.front() << " ";
        temp.pop();
    }
    std::cout << std::endl;
    
    // Reverse the queue
    reverseQueue(q);

    std::cout << "Reversed queue: ";
    while (!q.empty()) {
        std::cout << q.front() << " ";
        q.pop();
    }
    std::cout << std::endl;
    
    return 0;
}
