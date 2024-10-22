#
# @lc app=leetcode id=160 lang=python3
#
# [160] Intersection of Two Linked Lists
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        # 1. Initialize two pointers, one for each list
        pointerA = headA
        pointerB = headB
        
        # 2. Traverse both lists; when reaching the end of one list, continue from the other list's head
        while pointerA != pointerB:
            # 3. If pointerA reaches the end, redirect to headB, else move to the next node
            pointerA = pointerA.next if pointerA else headB
            
            # 4. If pointerB reaches the end, redirect to headA, else move to the next node
            pointerB = pointerB.next if pointerB else headA
            
        # 5. Once pointerA and pointerB are the same, return either pointer (the intersection point or None)
        return pointerA

# @lc code=end

