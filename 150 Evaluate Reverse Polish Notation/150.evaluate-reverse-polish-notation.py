#
# @lc app=leetcode id=150 lang=python3
#
# [150] Evaluate Reverse Polish Notation
#

# @lc code=start
from typing import List

class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        # 1. Initialize an empty stack to store operands
        stack = []

        # 2. Define operations in a dictionary for easy access
        operations = {
            '+': lambda x, y: x + y,
            '-': lambda x, y: x - y,
            '*': lambda x, y: x * y,
            '/': lambda x, y: int(x / y),  # Python automatically performs floor division for int
        }

        # 3. Iterate over each token in the tokens list
        for token in tokens:
            if token in operations:
                # 4. If token is an operator, pop the last two numbers from stack
                y, x = stack.pop(), stack.pop()
                # 5. Apply the operation and push the result back onto the stack
                stack.append(operations[token](x, y))
            else:
                # 6. If token is a number, convert it to integer and push onto stack
                stack.append(int(token))
        
        # 7. Final result will be the only element left in the stack
        return stack[0] 
# @lc code=end

