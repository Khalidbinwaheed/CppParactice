#include<iostream>
#include <queue>
using namespace std;
int main()
{
    Queue <int> myQueue;
    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);
    myQueue.push(4);
    myQueue.push(5);


    cout <<"Size of the queue is: "<< myQueue.size() << endl;
    cout << "Front element of the queue is: "<< myQueue.front() << endl;
    cout << "Back element of the queue is: "<< myQueue.back() << endl;
    cout << "Element popped from the queue is: "<< myQueue.pop() << endl;
}