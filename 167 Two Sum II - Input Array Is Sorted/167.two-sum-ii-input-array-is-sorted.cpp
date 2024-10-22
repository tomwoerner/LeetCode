/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input Array Is Sorted
 */

// @lc code=start
#include <vector>
#include <iostream>

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;  // 1. Initialize the left pointer at the start of the array
        int right = numbers.size() - 1;  // 2. Initialize the right pointer at the end of the array

        while (left < right) {  // 3. Continue until the pointers meet
            int current_sum = numbers[left] + numbers[right];  // 4. Calculate the sum of the two pointed numbers

            if (current_sum == target) {  // 5. Check if the current sum is equal to the target
                return {left + 1, right + 1};  // 6. Return indices (1-indexed)
            } 
            else if (current_sum < target) {  // 7. If the sum is less than the target, move the left pointer right
                left++;
            } 
            else {  // 8. If the sum is greater than the target, move the right pointer left
                right--;
            }
        }
        return {};  // This line should never be reached as per problem statement.
    }
};
// @lc code=end

