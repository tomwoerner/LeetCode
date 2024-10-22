/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // 1. Initialize two pointers, one for each list
        ListNode *pointerA = headA;
        ListNode *pointerB = headB;
        
        // 2. Traverse both lists; when reaching the end of one list, continue from the other list's head
        while (pointerA != pointerB) {
            // 3. If pointerA reaches the end, redirect to headB, else move to the next node
            pointerA = pointerA ? pointerA->next : headB;
            
            // 4. If pointerB reaches the end, redirect to headA, else move to the next node
            pointerB = pointerB ? pointerB->next : headA;
        }
        
        // 5. Once pointerA and pointerB are the same, return either pointer (the intersection point or nullptr)
        return pointerA;
    }
};

// @lc code=end

