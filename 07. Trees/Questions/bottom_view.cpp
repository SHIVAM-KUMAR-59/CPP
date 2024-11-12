/*
Given a binary tree, return an array where elements represent the bottom view of the binary tree from left to right.

Note: If there are multiple bottom-most nodes for a horizontal distance from the root, then the latter one in the level traversal is considered. For example, in the below diagram, 3 and 4 are both the bottommost nodes at a horizontal distance of 0, here 4 will be considered.
*/

#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

class Solution {
  public:
    vector<int> bottomView(Node *root) {
    }
};