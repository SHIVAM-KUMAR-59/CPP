/*
Given a Binary Tree of size n, your task is to return the count of all the non-leaf nodes of the given binary tree.
*/

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

class Solution {
public:
    int countNonLeafNodes(Node* root) {
        // If root is nullptr or a leaf node, return 0 as it’s not a non-leaf node.
        if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
            return 0;
        }
        
        // Count this node as a non-leaf node, then count in left and right subtrees.
        return 1 + countNonLeafNodes(root->left) + countNonLeafNodes(root->right);
    }
};