#
# @lc app=leetcode id=142 lang=python3
#
# [142] Linked List Cycle II
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # 1. Use two pointers, slow and fast
        slow = fast = head

        # 2. Move the slow pointer by one step and fast pointer by two steps until they meet
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            
            # 3. If they meet, there is a cycle
            if slow == fast:
                break
        else:
            # 4. If there is no cycle, return None
            return None

        # 5. Move one pointer to the head, keep the other at the meeting point
        slow = head
        while slow != fast:
            slow = slow.next
            fast = fast.next

        # 6. Both pointers meet at the start of the cycle
        return slow

# @lc code=end

