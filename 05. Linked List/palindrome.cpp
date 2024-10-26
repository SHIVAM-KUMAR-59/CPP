// Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

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

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseLinkedList(ListNode **head) {
    ListNode* prev = nullptr;
    ListNode* curr = *head;
    ListNode* next = nullptr;
    while(curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
    return *head;
}

ListNode* findMid(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;
    while(fast && fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        ListNode* mid = findMid(head);
        ListNode* nextToMid = mid->next;
        mid->next = nullptr;

        ListNode* reversed = reverseLinkedList(&nextToMid);
        ListNode* p1 = head;
        ListNode* p2 = reversed;

        while(p2) {
            if(p1->val != p2->val) {
                reverseLinkedList(&reversed);  // Restore original structure if needed
                mid->next = reversed;
                return false;
            }
            p1 = p1->next;
            p2 = p2->next;
        }

        reverseLinkedList(&reversed);  // Restore original structure if needed
        mid->next = reversed;
        return true;
    }
};
