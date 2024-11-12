/*
Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.
*/
#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution {
public:
    // Function to calculate the diameter of a binary tree.
    int diameter(Node* root) {
        int diameter = 0;
        height(root, diameter); // Compute height and update diameter along the way.
        return diameter;
    }

private:
    // Helper function to compute height of tree and update the diameter.
    int height(Node* root, int& diameter) {
        if (root == nullptr) {
            return 0;
        }
        
        // Recursively calculate the height of left and right subtrees.
        int leftHeight = height(root->left, diameter);
        int rightHeight = height(root->right, diameter);
        
        // Calculate the potential diameter passing through the current node.
        diameter = std::max(diameter, leftHeight + rightHeight + 1);
        
        // Return the height of the current subtree.
        return 1 + std::max(leftHeight, rightHeight);
    }
};
