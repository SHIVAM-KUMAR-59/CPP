
/*
Given a binary tree having n nodes. Check whether all of its nodes have a value equal to the sum of their child nodes. Return 1 if all the nodes in the tree satisfy the given properties, else it returns 0. For every node, the data value must be equal to the sum of the data values in the left and right children. Consider the data value 0 for a NULL child. Also, leaves are considered to follow the property.
*/

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

class Solution {
public:
    // Function to check whether all nodes of a tree have the value equal to the sum of their child nodes.
    int isSumProperty(Node *root) {
        // If the node is null or a leaf node, it satisfies the property
        if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
            return 1;
        }
        
        // Calculate the value of the left and right children
        int left = getValue(root->left);
        int right = getValue(root->right);
        
        // Check if the sum property holds at the current node
        if (root->data == left + right && 
            isSumProperty(root->left) && 
            isSumProperty(root->right)) {
            return 1;
        }
        
        // If the sum property does not hold at the current node
        return 0;
    }
    
private:
    // Helper function to get the value of a node
    int getValue(Node* root) {
        if (root == nullptr) {
            return 0;
        }
        return root->data;
    }
};
