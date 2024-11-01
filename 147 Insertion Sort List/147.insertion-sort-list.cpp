/*
 * @lc app=leetcode id=147 lang=cpp
 *
 * [147] Insertion Sort List
 */

// @lc code=start
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
#include <iostream>

// Definition for singly-linked list.
/*struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};*/

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        // 1. Initialize a dummy node as the head of the sorted list.
        ListNode* dummy = new ListNode(0);
        ListNode* cur = head;  // Start with the head of the original list.
        
        while (cur) { // 2. Process each node in the original list.
            ListNode* next_node = cur->next; // Temporarily store the next node.         
            ListNode* position = dummy; // 3. Find the right position in the sorted list.
            while (position->next && position->next->val < cur->val) {
                position = position->next;
            }
            
            cur->next = position->next; // 4. Insert the cur node in the sorted list.
            position->next = cur;
            cur = next_node; // 5. Move to the next node in the original list.
        }
        
        ListNode* sorted_head = dummy->next;  // 6. Return the sorted list, starting from dummy's next.
        delete dummy;  // Clean up the dummy node.
        return sorted_head;
    }
};

// @lc code=end

