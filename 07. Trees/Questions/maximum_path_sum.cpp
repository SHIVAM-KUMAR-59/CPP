/*
A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty path.
*/

#include<iostream>
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
int maxGain(TreeNode* node, int& maxSum) {
        if (node == nullptr) return 0;  // Base case: return 0 if the node is null
        
        // Recursively calculate the maximum gain from the left and right subtrees
        int leftGain = max(maxGain(node->left, maxSum), 0);  // Ignore negative paths
        int rightGain = max(maxGain(node->right, maxSum), 0);  // Ignore negative paths
        
        // Calculate the maximum path sum passing through the current node
        int currentPathSum = node->val + leftGain + rightGain;
        
        // Update the global maximum sum if the current path sum is larger
        maxSum = max(maxSum, currentPathSum);
        
        // Return the maximum gain the current node can contribute to its parent
        return node->val + max(leftGain, rightGain);
    } 

    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;  // Initialize the maxSum to the smallest possible value
        maxGain(root, maxSum);  // Calculate the maximum gain for the tree
        return maxSum;  // Return the final result
    }
};