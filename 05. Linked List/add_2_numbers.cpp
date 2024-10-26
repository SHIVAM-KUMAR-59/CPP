/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

*/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1, *temp2 = l2;
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        int carry = 0;
        while(temp1 != NULL  || temp2 != NULL) {
            int sum = carry;
            if(temp1 != NULL) {
                sum += temp1->val;
                temp1 = temp1->next;
            }
            if(temp2 != NULL) {
                sum += temp2->val;
                temp2 = temp2->next;
            }
            carry = sum / 10;
            current->next = new ListNode(sum % 10);
            current = current->next;
        }
        if(carry > 0) {
            current->next = new ListNode(carry);
        }
        return dummy->next;
    }
};