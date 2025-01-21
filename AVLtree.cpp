#include <iostream>
#include <algorithm> // For std::max

// Node structure for the AVL tree
struct Node {
    int key;        // Data stored in the node
    Node *left;     // Pointer to the left child
    Node *right;    // Pointer to the right child
    int height;     // Height of the subtree rooted at this node

    Node(int k) : key(k), left(nullptr), right(nullptr), height(1) {} 
};

// Function to get the height of a node (handles null nodes)
int height(Node* node) {
    return node ? node->height : 0;
}

// Function to update the height of a node
void updateHeight(Node* node) {
    if (node) {
        node->height = std::max(height(node->left), height(node->right)) + 1;
    }
}

// Function to calculate the balance factor of a node
int balanceFactor(Node* node) {
    return node ? height(node->left) - height(node->right) : 0;
}

// Right rotation
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    updateHeight(y);
    updateHeight(x);
    return x; // Return new root
}


// Left rotation
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    updateHeight(x);
    updateHeight(y);
    return y; // Return new root
}


// Function to perform rotations if required
Node* balance(Node* node) {
    updateHeight(node);

    int balance = balanceFactor(node);

    // Left Heavy Case
    if(balance > 1) {
        if(balanceFactor(node->left) < 0) {
            node->left = leftRotate(node->left);
        }
         return rightRotate(node);
    }


    // Right Heavy Case
    if(balance < -1) {
      if(balanceFactor(node->right) > 0) {
            node->right = rightRotate(node->right);
        }
        return leftRotate(node);
    }

    return node; // Return balanced subtree root
}

// Function to insert a new node
Node* insert(Node* node, int key) {
    if (!node) return new Node(key); // Base case: empty subtree, create new node

    if (key < node->key) {
        node->left = insert(node->left, key);
    } else if (key > node->key) {
        node->right = insert(node->right, key);
    } else {
        return node; // Duplicate keys not allowed
    }

    return balance(node); // Balance the tree after insertion
}

// Function to find the node with minimum key in a subtree
Node* minKeyNode(Node* node){
    Node* current = node;
    while(current->left != nullptr){
        current = current->left;
    }
    return current;
}


// Function to remove a key
Node* remove(Node* node, int key) {
    if (!node) return node; // Base case: key not found

    if(key < node->key) {
        node->left = remove(node->left, key);
    } else if (key > node->key) {
        node->right = remove(node->right, key);
    } else {
        //Node with key found

        //Node with one or no child
        if(node->left == nullptr || node->right == nullptr) {
             Node* temp = node->left ? node->left : node->right; //Get the non-null child if available
             
             if(temp == nullptr) { //if no children
                temp = node;
                node = nullptr;
             } else {
                 *node = *temp; // Copy contents from non-null child into current node
             }

             delete temp; // Delete node after copying/removing the reference

        } else {
            // Node has two children, need to find the in order successor(min value node in the right subtree)
            Node* temp = minKeyNode(node->right);

            node->key = temp->key;

            node->right = remove(node->right,temp->key);

        }
    }

    if(!node) return node; //if node was deleted no need to balance 

    return balance(node); // Balance the tree after deletion
}


// Function to print tree (inorder traversal)
void inorder(Node* node) {
    if(node){
      inorder(node->left);
      std::cout << node->key << " ";
      inorder(node->right);
    }
}

// Function to deallocate memory used by tree
void deleteTree(Node* node) {
    if (node) {
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
}

int main() {
    Node* root = nullptr;

    // Inserting
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    std::cout << "Inorder Traversal after insertion: ";
    inorder(root);
    std::cout << std::endl;

     // Deleting
    root = remove(root, 30);

     std::cout << "Inorder Traversal after removal: ";
    inorder(root);
    std::cout << std::endl;

    deleteTree(root);
    return 0;
}