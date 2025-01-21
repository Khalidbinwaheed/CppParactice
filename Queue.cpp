#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> myQueue;  
    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);
    myQueue.push(4);
    myQueue.push(5);

    cout << "Size of the queue is: " << myQueue.size() << endl;
    myQueue.pop();
    myQueue.pop();
    myQueue.pop();
    myQueue.pop();
    cout << "Size of the queue is: " << myQueue.size() << endl;
    
    return 0;
}
