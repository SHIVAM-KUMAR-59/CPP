
/*
Given a Binary Search Tree. Your task is to complete the function which will return the kth largest element without doing any modification in the Binary Search Tree.
*/

struct Node {
    int data;
    Node *left;
    Node *right;
};

class Solution {
public:
    int kthLargest(Node *root, int &k) {
        // Base case
        if (root == nullptr) {
            return -1;
        }
        
        // Start with the right subtree for reverse inorder traversal
        int right = kthLargest(root->right, k);
        if (k == 0) {
            return right; // Found the kth largest in the right subtree
        }
        
        // Decrement k and check if current node is the kth largest
        k--;
        if (k == 0) {
            return root->data; // Found the kth largest at root
        }
        
        // Otherwise, continue to the left subtree
        return kthLargest(root->left, k);
    }
};