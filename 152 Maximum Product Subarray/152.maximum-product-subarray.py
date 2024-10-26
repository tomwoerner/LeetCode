#
# @lc app=leetcode id=152 lang=python3
#
# [152] Maximum Product Subarray
#

# @lc code=start
from typing import List

class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        # 1. Initialize variables to keep track of maximum, minimum product, and the final result.
        max_product = nums[0]      # Maximum product of subarray ending at the current index
        min_product = nums[0]      # Minimum product of subarray ending at the current index (important for negatives)
        result = nums[0]           # Result variable to store the maximum product found

        # 2. Iterate through the list from the second element
        for i in range(1, len(nums)):
            # If the current number is negative, swapping max and min helps to maximize the product
            if nums[i] < 0:
                max_product, min_product = min_product, max_product

            # 3. Update max_product and min_product for the current index
            max_product = max(nums[i], max_product * nums[i])
            min_product = min(nums[i], min_product * nums[i])

            # 4. Update the result with the maximum of max_product
            result = max(result, max_product)

        # 5. Return the result
        return result
 
# @lc code=end

