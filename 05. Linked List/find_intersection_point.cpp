/*
Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.
*/

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;

        ListNode *pA = headA;
        ListNode *pB = headB;

        // Traverse both lists. When a pointer reaches the end, switch it to the other list's head.
        while (pA != pB) {
            pA = pA ? pA->next : headB;
            pB = pB ? pB->next : headA;
        }

        // Either they meet at the intersection node, or both become nullptr if no intersection exists.
        return pA;
    }
};
