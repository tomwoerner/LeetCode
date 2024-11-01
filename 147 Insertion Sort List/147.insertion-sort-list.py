#
# @lc app=leetcode id=147 lang=python3
#
# [147] Insertion Sort List
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
from typing import Optional

# Definition for singly-linked list.
'''
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
'''
class Solution:
    def insertionSortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(0) # 1. Initialize a dummy node as the head of the sorted list.
        cur = head  # Start with the head of the original list.
        
        while cur: # 2. while current is not null (not the end of list)
            next_node = cur.next # Temporarily store the next node.
            
            position = dummy # 3. Find the right position in the sorted list.
            while position.next and position.next.val < cur.val:
                position = position.next
            cur.next = position.next # 4. Insert the current node in the sorted list.
            position.next = cur
            cur = next_node # 5. Move to the next node in the original list.
            
        return dummy.next # 6. Return the sorted list, starting from dummy's next.

# @lc code=end

