#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the binary tree
struct node {
    int data;
    struct node *right, *left;
};

// Function to perform level order traversal
void level_order_traversal(struct node *root) {
    if (root == NULL) {
        return;
    }

    // Initialize a queue using an array to hold nodes at each level
    struct node* queue[100];
    int front = 0, rear = 0;

    // Enqueue the root node
    queue[rear++] = root;

    while (front < rear) {
        // Dequeue a node from the queue
        struct node *current = queue[front++];

        // Print the data of the current node
        printf("%d ", current->data);

        // Enqueue the left child if it exists
        if (current->left != NULL) {
            queue[rear++] = current->left;
        }

        // Enqueue the right child if it exists
        if (current->right != NULL) {
            queue[rear++] = current->right;
        }
    }
}

int main() {
    // Manually create the binary tree and allocate memory for each node
    struct node *root = (struct node*)malloc(sizeof(struct node));
    struct node *node10 = (struct node*)malloc(sizeof(struct node));
    struct node *node20 = (struct node*)malloc(sizeof(struct node));
    struct node *node30 = (struct node*)malloc(sizeof(struct node));
    struct node *node40 = (struct node*)malloc(sizeof(struct node));
    struct node *node50 = (struct node*)malloc(sizeof(struct node));
    struct node *node60 = (struct node*)malloc(sizeof(struct node));

    // Assign values to the nodes
    root->data = 1;
    root->left = node10;
    root->right = node20;

    node10->data = 10;
    node10->left = NULL;
    node10->right = NULL;

    node20->data = 20;
    node20->left = node30;
    node20->right = node40;

    node30->data = 30;
    node30->left = node60;
    node30->right = node50;

    node40->data = 40;
    node40->left = NULL;
    node40->right = NULL;

    node50->data = 50;
    node50->left = NULL;
    node50->right = NULL;

    node60->data = 60;
    node60->left = NULL;
    node60->right = NULL;

    // Perform level order traversal of the binary tree
    printf("Level Order Traversal: ");
    level_order_traversal(root);
    printf("\n");

    // Free allocated memory (important to prevent memory leaks)
    free(root);
    free(node10);
    free(node20);
    free(node30);
    free(node40);
    free(node50);
    free(node60);

    return 0;
}
