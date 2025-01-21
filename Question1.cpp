#include <iostream>
#include <queue>
#include <vector>
#include <algorithm> // for std::reverse

bool is_palindrome(std::queue<int> q) {
    std::vector<int> elements;
    
    // Convert queue to vector
    while (!q.empty()) {
        elements.push_back(q.front());
        q.pop();
    }
    
    // Check if the vector is a palindrome
    std::vector<int> reversed_elements = elements;
    std::reverse(reversed_elements.begin(), reversed_elements.end());
    
    return elements == reversed_elements;
}

int main() {
    std::queue<int> q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(2);
    q1.push(1);

    if (is_palindrome(q1)) {
        std::cout << "The queue is a palindrome." << std::endl;
    } else {
        std::cout << "The queue is not a palindrome." << std::endl;
    }
    
    std::queue<int> q2;
    q2.push(1);
    q2.push(2);
    q2.push(3);
    q2.push(4);
    q2.push(5);

    if (is_palindrome(q2)) {
        std::cout << "The queue is a palindrome." << std::endl;
    } else {
        std::cout << "The queue is not a palindrome." << std::endl;
    }

    return 0;
}
