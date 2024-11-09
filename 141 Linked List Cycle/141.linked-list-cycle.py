#
# @lc app=leetcode id=141 lang=python3
#
# [141] Linked List Cycle
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

from typing import Optional

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        # 1. Initialize two pointers, slow and fast, both starting at the head of the linked list
        slow = head
        fast = head

        # 2. Traverse the list until the fast pointer or its next node is None (indicating no cycle)
        while fast and fast.next:
            # 3. Move the slow pointer one step forward
            slow = slow.next
            # 4. Move the fast pointer two steps forward
            fast = fast.next.next

            # 5. If slow and fast meet, a cycle exists; return True
            if slow == fast:
                return True

        # 6. If the loop terminates without slow and fast meeting, there is no cycle; return False
        return False

# @lc code=end

