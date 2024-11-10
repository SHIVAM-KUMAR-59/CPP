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

// Function to find the minimum node in a given subtree
struct node *findMin(struct node *root) {
    // Traverse left to find the minimum value node
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to delete a node with a given value from the BST
void deletion(struct node **root, int val) {
    // Base case: if the tree is empty, do nothing
    if (*root == NULL) {
        return;
    }

    // Find the node to be deleted
    if (val == (*root)->data) {
        // Case 1: Node is a leaf node
        if (((*root)->left == NULL) && ((*root)->right == NULL)) {
            cout << "Node is a leaf node" << endl;
            free(*root);  // Free the memory for the node
            *root = NULL; // Set the pointer to NULL
        }
        // Case 2: Node has only a right child
        else if (((*root)->left == NULL) && ((*root)->right != NULL)) {
            cout << "Node has right child" << endl;
            struct node *temp = *root;
            *root = (*root)->right; // Replace node with right child
            free(temp);
        }
        // Case 3: Node has only a left child
        else if (((*root)->right == NULL) && ((*root)->left != NULL)) {
            cout << "Node has left child" << endl;
            struct node *temp = *root;
            *root = (*root)->left; // Replace node with left child
            free(temp);
        }
        // Case 4: Node has two children
        else {
            cout << "Node has two children" << endl;
            // Find the minimum node in the right subtree
            struct node *temp = findMin((*root)->right);
            // Replace current node's data with the minimum node's data
            (*root)->data = temp->data;
            // Delete the duplicate node from the right subtree
            deletion(&((*root)->right), temp->data);
        }
    }
    // If the value is greater, move to the right subtree
    else if (val > (*root)->data) {
        deletion(&((*root)->right), val);
    }
    // If the value is smaller, move to the left subtree
    else {
        deletion(&((*root)->left), val);
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
    insert(&root, 14);
    insert(&root, 12);
    insert(&root, 16);

    // Delete a node with value 14
    deletion(&root, 14);
    
    // Perform in-order traversal and print the result
    cout << "InOrder Traversal: ";
    inOrder(root);
    cout << endl;

    return 0;
}
