/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */

// @lc code=start
#include <vector>
#include <string>
#include <stack>
#include <stdexcept>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // Step 1: Initialize a stack for intermediate results.
        stack<int> stack;

        // Step 2: Iterate through tokens to evaluate expression.
        for (const string& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                // Step 3: Pop two elements to apply operation.
                int b = stack.top(); stack.pop();
                int a = stack.top(); stack.pop();

                // Step 4: Perform operation based on token.
                if (token == "+") stack.push(a + b);
                else if (token == "-") stack.push(a - b);
                else if (token == "*") stack.push(a * b);
                else if (token == "/") stack.push(a / b); // Integer division.
            } else {
                // Step 5: Convert number token to integer and push to stack.
                stack.push(stoi(token));
            }
        }

        // Step 6: Return the result from the stack.
        return stack.top();
    }
};

// @lc code=end

