#
# @lc app=leetcode id=138 lang=python3
#
# [138] Copy List with Random Pointer
#

# @lc code=start
"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if not head:
            return None
        
        # 1. Insert cloned nodes after each original node.
        current = head
        while current:
            new_node = Node(current.val)  # Create new node.
            new_node.next = current.next
            current.next = new_node
            current = new_node.next  # Move to the next original node.
        
        # 2. Set the random pointers for the cloned nodes.
        current = head
        while current:
            if current.random:  # Set random if it exists.
                current.next.random = current.random.next
            current = current.next.next  # Skip to the next original node.
        
        # 3. Separate the cloned list from the original list.
        original = head
        copy = head.next
        copy_head = copy
        while original:
            original.next = original.next.next  # Restore original list.
            if copy.next:
                copy.next = copy.next.next  # Set next for cloned list.
            original = original.next
            copy = copy.next
        
        return copy_head        
# @lc code=end

