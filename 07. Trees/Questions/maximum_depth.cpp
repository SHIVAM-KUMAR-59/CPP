/*
Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
*/

#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // Function to calculate the maximum depth of the binary tree
    int maxDepth(TreeNode* root) {
        // Base case: If the root is null, the depth is 0
        if (root == nullptr) {
            return 0;
        }
        
        // Recursively calculate the depth of the left and right subtrees
        int left_height = maxDepth(root->left);
        int right_height = maxDepth(root->right);
        
        // Return the maximum of the two depths plus one for the current node
        return max(left_height, right_height) + 1;
    }
};
