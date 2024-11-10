#include <iostream>
#include <stdlib.h>
using namespace std;

// Define the structure for a node in the binary search tree (BST)
struct node {
    int data;           // Value of the node
    struct node *left;  // Pointer to the left child
    struct node *right; // Pointer to the right child
};

// Function to create a new node with a given value
struct node *createNode(int val) {
    // Allocate memory for the new node
    struct node *newNode = (struct node *) malloc(sizeof(struct node));
    
    // Check if memory allocation was successful
    if (!newNode) {
        printf("Memory error\n");
        return NULL; // Return NULL if allocation failed
    }
    
    // Initialize the new node with the given value and set left and right pointers to NULL
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the binary search tree
void insert(struct node **root, int val) {
    // If the tree is empty, create a new node as the root
    if (*root == NULL) {
        *root = createNode(val);
        return;
    }

    // Recursively insert the node in the correct position
    if (val > (*root)->data) {
        // If value is greater than root's data, insert in the right subtree
        insert(&((*root)->right), val);
    } else if (val < (*root)->data) {
        // If value is less than root's data, insert in the left subtree
        insert(&((*root)->left), val);
    }
}

// Function to perform in-order traversal of the BST
void inOrder(struct node *root) {
    // Traverse the tree in in-order (left, root, right)
    if (root != NULL) {
        inOrder(root->left);         // Visit the left subtree
        cout << root->data << " ";   // Visit the root
        inOrder(root->right);        // Visit the right subtree
    }
}

int main() {
    // Create the root node of the BST
    struct node *root = createNode(10);

    // Insert additional nodes into the BST
    insert(&root, 1);
    insert(&root, 2);
    insert(&root, 11);
    insert(&root, 12);
    
    // Perform in-order traversal and print the result
    cout << "InOrder Traversal: ";
    inOrder(root);
    cout << endl;

    return 0;
}
