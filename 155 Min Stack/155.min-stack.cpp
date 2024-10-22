/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

// @lc code=start
class MinStack {
public:
    /** 1. Initialize two stacks: one for regular stack operations, one for tracking minimum values. */
    MinStack() {}

    /** 2. Push the value to the regular stack. 
        3. If the min stack is empty or the new value is smaller than or equal to the current minimum, push it onto the min stack. */
    void push(int val) {
        stack.push_back(val);
        if (min_stack.empty() || val <= min_stack.back()) {
            min_stack.push_back(val);
        }
    }

    /** 4. Pop the top value from the regular stack.
        5. If the popped value is equal to the top of the min stack, pop it from the min stack as well. */
    void pop() {
        if (stack.back() == min_stack.back()) {
            min_stack.pop_back();
        }
        stack.pop_back();
    }

    /** 6. Return the top element of the regular stack. */
    int top() {
        return stack.back();
    }

    /** 7. Return the top element of the min stack, which is the current minimum. */
    int getMin() {
        return min_stack.back();
    }

private:
    std::vector<int> stack;      // Stack to store all elements
    std::vector<int> min_stack;  // Stack to store minimum values
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

