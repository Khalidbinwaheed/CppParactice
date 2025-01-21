#include<iostream>
using namespace std;

struct node{
    int data ;
    node *left;
    node *right;

};

struct node *newNode(int data){
    struct node *binary = new node;
    binary->data = data;
    binary->left = binary->right = NULL;
    return binary;

}

int main()
{
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    
    cout << "Binary tree created successfully" << endl;
    cout<< "Root node is: "<< root->left->data << endl;
    return 0;

}