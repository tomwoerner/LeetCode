/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
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
using namespace std;

class Solution {
public:
    bool hasCycle(ListNode *head) {
        // 1. Initialize two pointers, slow and fast, both starting at the head of the linked list
        ListNode *slow = head;
        ListNode *fast = head;

        // 2. Traverse the list until the fast pointer or its next node is NULL (indicating no cycle)
        while (fast != nullptr && fast->next != nullptr) {
            // 3. Move the slow pointer one step forward
            slow = slow->next;
            // 4. Move the fast pointer two steps forward
            fast = fast->next->next;

            // 5. If slow and fast meet, a cycle exists; return true
            if (slow == fast) {
                return true;
            }
        }

        // 6. If the loop terminates without slow and fast meeting, there is no cycle; return false
        return false;
    }
};

// @lc code=end

