/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <vector>
#include <stack> // for iterative solution
using namespace std;

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        preorder(root, result);  // Call the helper function with root and result vector.
        return result;
    }

private:
    void preorder(TreeNode* node, vector<int>& result) {
        // 1. Base case: if node is null, return.
        if (!node) return;
        
        // 2. Visit the node (append its value).
        result.push_back(node->val);
        
        // 3. Traverse the left subtree.
        preorder(node->left, result);
        
        // 4. Traverse the right subtree.
        preorder(node->right, result);
    }
};

/* iterative solution
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root) return result;  // 1. If the root is null, return an empty result.

        stack<TreeNode*> stack;
        stack.push(root);  // 2. Initialize the stack with the root node.

        while (!stack.empty()) {
            // 3. Pop the top node from the stack and visit it.
            TreeNode* node = stack.top();
            stack.pop();
            result.push_back(node->val);

            // 4. Push the right child first (if exists), so the left child is processed first.
            if (node->right) stack.push(node->right);
            if (node->left) stack.push(node->left);
        }

        return result;  // 5. Return the result containing the preorder traversal.
    }
};
*/

// @lc code=end

