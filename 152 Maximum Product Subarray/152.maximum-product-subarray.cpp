/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // 1. Initialize variables for max, min product, and final result
        int max_product = nums[0];   // Maximum product of subarray ending at the current index
        int min_product = nums[0];   // Minimum product of subarray ending at the current index (to handle negatives)
        int result = nums[0];        // To store the maximum product found

        // 2. Iterate through the array starting from the second element
        for (int i = 1; i < nums.size(); i++) {
            // If the current element is negative, swap max_product and min_product
            if (nums[i] < 0) {
                swap(max_product, min_product);
            }

            // 3. Update max_product and min_product for the current index
            max_product = max(nums[i], max_product * nums[i]);
            min_product = min(nums[i], min_product * nums[i]);

            // 4. Update the result with the maximum of max_product
            result = max(result, max_product);
        }

        // 5. Return the result
        return result;
    }
};
// @lc code=end

