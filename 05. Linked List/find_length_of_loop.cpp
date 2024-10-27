// Given a Linked List, return the length of the loop if present else return 0

#include<iostream>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    
    // Default constructor
    ListNode() : val(0), next(nullptr) {}

    // Constructor that initializes with a given value and null next pointer
    ListNode(int x) : val(x), next(nullptr) {}

    // Constructor that initializes with a given value and a pointer to the next node
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *length(ListNode *head) {
        
    }
};
