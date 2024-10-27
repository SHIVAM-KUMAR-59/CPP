// Given a Linked List, return the length of the loop if present else return 0

#include<iostream>
#include<map>
using namespace std;

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
    int lengthOfLoop(ListNode *head) {
        // map<ListNode*, int> mpp;
        // int position = 1;
        // ListNode *temp = head;

        // while (temp != nullptr) {
        //     if (mpp.find(temp) != mpp.end()) {
        //         // Loop detected, calculate the length of the loop
        //         return position - mpp[temp];
        //     }
        //     // Store the current node in the map with its position
        //     mpp[temp] = position;
        //     temp = temp->next;
        //     position++;
        // }

        ListNode *slow = head;
        ListNode *fast = head;
        int length = 0;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                // Loop detected, calculate the length of the loop
                length = 1;
                ListNode *temp = slow;
                while (temp->next != slow) {
                    length++;
                    temp = temp->next;
                }
                return length;
            }
        }
        return 0;  // No loop detected
    }
};
