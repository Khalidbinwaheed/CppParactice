#include <iostream>
using namespace std;
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};


struct Node* newNode(int data){
    struct Node* node = new struct Node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
} 
int main(){
    


    return 0;
}