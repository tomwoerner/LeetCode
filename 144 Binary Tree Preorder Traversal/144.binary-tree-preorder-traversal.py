#
# @lc app=leetcode id=144 lang=python3
#
# [144] Binary Tree Preorder Traversal
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
# Definition for a binary tree node.
class Solution:
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
    # Recursive solution
        result = []
        def preorder(node):
            if not node:
                return
            result.append(node.val)
            preorder(node.left)
            preorder(node.right)
        
        preorder(root)
        return result
    
    # Iterative solution
    '''
        if not root:
            return []
        
        result = []
        stack = [root]
        
        while stack:
            node = stack.pop()
            result.append(node.val)
            if node.right:
                stack.append(node.right)
            if node.left:
                stack.append(node.left)
        
        return result
    '''
  
# @lc code=end

