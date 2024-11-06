#
# @lc app=leetcode id=143 lang=python3
#
# [143] Reorder List
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        # 1. Find the middle of the linked list
        slow, fast = head, head # set both pointers to head
        while fast and fast.next: # while fast and fast.next are not null (end of list)
            slow = slow.next # shift slow by 1
            fast = fast.next.next # shift fast by 2
        
        # 2. Reverse the second half of the list
        prev, curr = None, slow # split the list in two by setting prev to null
        while curr: # while curr is non-null
            temp = curr.next # store a temp var for next
            curr.next = prev # our next will then be null
            prev = curr # update the pointer
            curr = temp # reverse the link
        
        # 3. Merge the two halves
        first, second = head, prev # start the two lists
        while second and second.next: # while not reached end of second list
            temp1, temp2 = first.next, second.next # store next in temps because breaking links
            first.next = second # reassign to second
            second.next = temp1 # insert 2nd node 
            first, second = temp1, temp2 # shift the pointers
        
# @lc code=end

