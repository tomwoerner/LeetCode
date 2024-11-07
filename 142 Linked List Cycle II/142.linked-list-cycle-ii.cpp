/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>

class Solution {
public:
    ListNode* detectCycle(ListNode *head) {
        // 1. Use two pointers, slow and fast
        ListNode *slow = head;
        ListNode *fast = head;

        // 2. Move the slow pointer by one step and fast pointer by two steps until they meet
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            
            // 3. If they meet, there is a cycle
            if (slow == fast) {
                break;
            }
        }

        // 4. If there is no cycle, return NULL
        if (fast == NULL || fast->next == NULL) {
            return NULL;
        }

        // 5. Move one pointer to the head, keep the other at the meeting point
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        // 6. Both pointers meet at the start of the cycle
        return slow;
    }
};

// @lc code=end

