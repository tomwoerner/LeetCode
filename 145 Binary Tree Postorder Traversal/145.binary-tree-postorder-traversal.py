#
# @lc app=leetcode id=145 lang=python3
#
# [145] Binary Tree Postorder Traversal
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from typing import List, Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        result = []
        
        def postorder(node):
            if node:
                # Traverse left subtree
                postorder(node.left)
                # Traverse right subtree
                postorder(node.right)
                # Visit root node
                result.append(node.val)
        
        postorder(root)
        return result
    
'''
Iterative solution:
from typing import List, Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        if not root:
            return []

        # Initialize two stacks
        stack1 = [root]
        stack2 = []
        result = []

        # Process nodes
        while stack1:
            node = stack1.pop()
            stack2.append(node)
            # Push left and right children onto the first stack
            if node.left:
                stack1.append(node.left)
            if node.right:
                stack1.append(node.right)

        # Pop nodes from stack2 to get postorder result
        while stack2:
            result.append(stack2.pop().val)

        return result
'''
  
# @lc code=end

