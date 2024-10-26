// Given the head of a linked list, remove the nth node from the end of the list and return its head.

#include<iostream>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast = head;
        ListNode *slow = head;
        for(int i = 0; i < n; i++){
            fast = fast -> next;
        }
        if(fast == NULL){
            return head->next;
        }
        while(fast -> next != NULL){
            fast = fast -> next;
            slow = slow -> next;
        }
        ListNode *delNode = slow -> next;
        slow -> next = delNode -> next;
        delete delNode;
        return head;
    }
};