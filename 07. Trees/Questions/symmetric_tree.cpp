/*
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return isSymmetricHelper(root->left, root->right);
    }
    
    bool isSymmetricHelper(TreeNode* leftNode, TreeNode* rightNode) {
        if (leftNode == nullptr && rightNode == nullptr) return true;
        if (leftNode == nullptr || rightNode == nullptr) return false;
        if (leftNode->val != rightNode->val) return false;
        return isSymmetricHelper(leftNode->left, rightNode->right) && isSymmetricHelper(leftNode->right, rightNode->left);
    }
};