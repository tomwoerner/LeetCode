#
# @lc app=leetcode id=167 lang=python3
#
# [167] Two Sum II - Input Array Is Sorted
#

# @lc code=start
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        # 1. Initialize two pointers: left starting at the beginning (0) and right at the end (length - 1)
        left, right = 0, len(numbers) - 1
        # 2. Iterate while left pointer is less than right pointer
        while left < right:
            # 3. Calculate the sum of the numbers at the left and right pointers
            current_sum = numbers[left] + numbers[right]
            # 4. Check if the current sum is equal to the target
            if current_sum == target:
                # 5. If equal, return the indices adjusted for 1-indexing
                return [left + 1, right + 1]
            # 6. If the current sum is less than the target, move the left pointer to the right
            elif current_sum < target:
                left += 1
            # 7. If the current sum is greater than the target, move the right pointer to the left
            else:
                right -= 1
# @lc code=end

