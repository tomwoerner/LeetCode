#
# @lc app=leetcode id=148 lang=python3
#
# [148] Sort List
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # 1. Check if the list is empty or has one node
        if not head or not head.next:
            return head

        # 2. Get the length of the linked list
        length = 0
        node = head
        while node:
            length += 1
            node = node.next

        # 3. Create a dummy node to use as a pre-head
        dummy = ListNode(0)
        dummy.next = head

        # 4. Iteratively split and merge lists of increasing size
        size = 1
        while size < length:
            tail, cur = dummy, dummy.next

            while cur:
                # 5. Split the list into two halves
                left = cur
                right = self.split(left, size)
                cur = self.split(right, size)

                # 6. Merge the two halves and attach to tail
                tail = self.merge(left, right, tail)

            size *= 2

        return dummy.next

    def split(self, head: ListNode, size: int) -> Optional[ListNode]:
        # Split the linked list after `size` nodes
        for i in range(size - 1):
            if head:
                head = head.next
        if not head:
            return None
        second = head.next
        head.next = None
        return second

    def merge(self, l1: ListNode, l2: ListNode, head: ListNode) -> ListNode:
        # Merge two sorted linked lists `l1` and `l2`, attaching result to `head`
        cur = head
        while l1 and l2:
            if l1.val < l2.val:
                cur.next = l1
                l1 = l1.next
            else:
                cur.next = l2
                l2 = l2.next
            cur = cur.next
        cur.next = l1 if l1 else l2
        while cur.next:
            cur = cur.next
        return cur
   
# @lc code=end

