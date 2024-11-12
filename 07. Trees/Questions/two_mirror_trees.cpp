/*
Given a Two Binary Trees, write a function that returns true if one is mirror of other, else returns false.
*/


struct Node{
    int data;
    Node* left, *right;
}; 

class Solution {
  public:
    int areMirror(Node* a, Node* b) {
        // Your code here
        if(a == nullptr && b == nullptr){
            return true;
        }
        
        
        if(a == nullptr || b == nullptr){
            return false;
        }
        
        if(a->data != b->data){
            return false;
        }
        
        return areMirror(a->left, b->right) && areMirror(a->right, b->left);
    }
};