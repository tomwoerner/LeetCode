#
# @lc app=leetcode id=155 lang=python3
#
# [155] Min Stack
#

# @lc code=start
class MinStack:
    def __init__(self):
        # 1. Initialize two stacks: one for regular stack operations, one for tracking minimum values.
        self.stack = []
        self.min_stack = []

    def push(self, val: int) -> None:
        # 2. Push the value to the regular stack.
        self.stack.append(val)
        # 3. If the min stack is empty or the new value is smaller than or equal to the current minimum, push it onto the min stack.
        if not self.min_stack or val <= self.min_stack[-1]:
            self.min_stack.append(val)

    def pop(self) -> None:
        # 4. Pop the top value from the regular stack.
        popped = self.stack.pop()
        # 5. If the popped value is equal to the top of the min stack, pop it from the min stack as well.
        if popped == self.min_stack[-1]:
            self.min_stack.pop()

    def top(self) -> int:
        # 6. Return the top element of the regular stack.
        return self.stack[-1]

    def getMin(self) -> int:
        # 7. Return the top element of the min stack, which is the current minimum.
        return self.min_stack[-1]
    
# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
# @lc code=end

