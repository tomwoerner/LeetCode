/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
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
using namespace std;

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        postorder(root, result);
        return result;
    }
    
private:
    void postorder(TreeNode* node, vector<int>& result) {
        if (node) {
            // Traverse left subtree
            postorder(node->left, result);
            // Traverse right subtree
            postorder(node->right, result);
            // Visit root node
            result.push_back(node->val);
        }
    }
};

/* Iterative solution:
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) return {};

        stack<TreeNode*> stack1, stack2;
        vector<int> result;

        stack1.push(root);

        while (!stack1.empty()) {
            TreeNode* node = stack1.top();
            stack1.pop();
            stack2.push(node);
            
            if (node->left) stack1.push(node->left);
            if (node->right) stack1.push(node->right);
        }

        while (!stack2.empty()) {
            result.push_back(stack2.top()->val);
            stack2.pop();
        }

        return result;
    }
}; */

// @lc code=end

