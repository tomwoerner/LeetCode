/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
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
class Solution {
public:
    void reorderList(ListNode* head) {
        // 1. Find the middle of the list using slow and fast pointers.
        ListNode *slow = head, *fast = head; // set both pointers to head
        while (fast && fast->next) { // while fast and fast.next are not null (end of list)
            slow = slow->next; // shift slow by 1
            fast = fast->next->next; // shift fast by 2
        }

        // 2. Reverse the second half starting from slow.
        ListNode *prev = nullptr, *curr = slow; // split the list in two by setting prev to null
        while (curr) { // while curr is non-null
            ListNode *next_temp = curr->next; // store a temp var for next
            curr->next = prev; // our next will then be null
            prev = curr; // update the pointer
            curr = next_temp; // reverse the link
        }

        // 3. Merge two halves by alternating nodes.
        ListNode *first = head, *second = prev; // start the two lists
        while (second->next) { // while not reached end of second list
            ListNode *temp1 = first->next; // store next in temps because breaking links
            ListNode *temp2 = second->next; 
            first->next = second; // reassign to second
            second->next = temp1; // insert 2nd node
            first = temp1; // shift the pointers
            second = temp2;
        }
    }
};
// @lc code=end

