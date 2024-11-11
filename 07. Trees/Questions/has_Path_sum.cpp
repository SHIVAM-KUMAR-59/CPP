/*
Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

A leaf is a node with no children.
*/

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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return false;
        }

        // Subtract the current node's value from targetSum
        targetSum -= root->val;

        // Check if we've reached a leaf node and if the path sum equals targetSum
        if (root->left == nullptr && root->right == nullptr) {
            return targetSum == 0;
        }

        // Recur on left and right children
        return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
    }
};