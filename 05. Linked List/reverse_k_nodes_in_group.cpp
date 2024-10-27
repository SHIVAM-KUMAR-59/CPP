/*
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.
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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;
        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode* findKthNode(ListNode* temp, int k) {
        while (temp != nullptr && --k > 0) {
            temp = temp->next;
        }
        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k <= 1 || !head) return head;

        ListNode* temp = head;
        ListNode* prevNode = nullptr;
        ListNode* newHead = nullptr;

        while (temp != nullptr) {
            ListNode* kthNode = findKthNode(temp, k);
            if (kthNode == nullptr) {
                if (prevNode) {
                    prevNode->next = temp;
                }
                break;
            }
            ListNode* nextNode = kthNode->next;
            kthNode->next = nullptr;

            ListNode* reversedHead = reverseList(temp);
            if (!newHead) {
                newHead = reversedHead;
            }

            if (prevNode) {
                prevNode->next = reversedHead;
            }

            prevNode = temp;
            temp = nextNode;
        }
        return newHead ? newHead : head;
    }
};