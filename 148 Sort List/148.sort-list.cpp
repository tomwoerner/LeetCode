/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
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

/*struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};*/

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        // 1. Check if the list is empty or has one node
        if (!head || !head->next) return head;

        // 2. Calculate the length of the list
        int length = 0;
        ListNode* node = head;
        while (node) {
            length++;
            node = node->next;
        }

        // 3. Create a dummy node to act as a pre-head
        ListNode dummy(0);
        dummy.next = head;

        // 4. Iteratively split and merge lists of increasing size
        for (int size = 1; size < length; size *= 2) {
            ListNode* tail = &dummy;
            ListNode* cur = dummy.next;

            while (cur) {
                // 5. Split the list into two halves
                ListNode* left = cur;
                ListNode* right = split(left, size);
                cur = split(right, size);

                // 6. Merge two halves and attach to tail
                tail = merge(left, right, tail);
            }
        }

        return dummy.next;
    }

private:
    ListNode* split(ListNode* head, int size) {
        // Split the list after `size` nodes
        for (int i = 1; head && i < size; i++) {
            head = head->next;
        }
        if (!head) return nullptr;
        ListNode* second = head->next;
        head->next = nullptr;
        return second;
    }

    ListNode* merge(ListNode* l1, ListNode* l2, ListNode* head) {
        // Merge two sorted lists l1 and l2
        ListNode* cur = head;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        cur->next = l1 ? l1 : l2;
        while (cur->next) {
            cur = cur->next;
        }
        return cur;
    }
};

// @lc code=end

