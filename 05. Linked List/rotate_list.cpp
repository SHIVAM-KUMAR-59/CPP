// Given the head of a linked list, rotate the list to the right by k places.

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
    int getLength(ListNode* head) {
        int length = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            length++;
            temp = temp->next;
        }
        return length;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        int length = getLength(head);
        k %= length;
        if (k == 0) return head;  // No rotation needed

        // Find the new tail (length - k - 1) and the new head (length - k)
        ListNode* newTail = head;
        for (int i = 1; i < length - k; ++i) {
            newTail = newTail->next;
        }
        
        ListNode* newHead = newTail->next;

        // Make the list circular and then break it at the new tail
        ListNode* tail = newHead;
        while (tail->next) {
            tail = tail->next;
        }
        tail->next = head;
        newTail->next = nullptr;

        return newHead;
    }
};