#
# @lc app=leetcode id=162 lang=python3
#
# [162] Find Peak Element
#

# @lc code=start
class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        # 1. Initialize two pointers: left and right to cover the entire array.
        left, right = 0, len(nums) - 1
        
        # 2. Perform binary search by adjusting the pointers based on comparison of mid and mid+1.
        while left < right:
            # 3. Calculate the middle index.
            mid = (left + right) // 2
            
            # 4. Check if the mid element is less than its next element.
            if nums[mid] < nums[mid + 1]:
                # 5. If true, move left pointer to mid + 1 (there's a peak on the right).
                left = mid + 1
            else:
                # 6. Otherwise, move right pointer to mid (there's a peak on the left).
                right = mid
        
        # 7. When left equals right, return the peak index.
        return left
# @lc code=end

