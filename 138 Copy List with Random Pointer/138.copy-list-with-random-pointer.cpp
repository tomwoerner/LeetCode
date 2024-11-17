/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
#include <iostream>
using namespace std;

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        // 1. Insert cloned nodes after each original node.
        Node* current = head;
        while (current) {
            Node* new_node = new Node(current->val); // Create new node.
            new_node->next = current->next;
            current->next = new_node;
            current = new_node->next; // Move to the next original node.
        }

        // 2. Set the random pointers for the cloned nodes.
        current = head;
        while (current) {
            if (current->random) { // Set random if it exists.
                current->next->random = current->random->next;
            }
            current = current->next->next; // Skip to the next original node.
        }

        // 3. Separate the cloned list from the original list.
        Node* original = head;
        Node* copy = head->next;
        Node* copy_head = copy;
        while (original) {
            original->next = original->next->next; // Restore original list.
            if (copy->next) {
                copy->next = copy->next->next; // Set next for cloned list.
            }
            original = original->next;
            copy = copy->next;
        }

        return copy_head;
    }
};
// @lc code=end

