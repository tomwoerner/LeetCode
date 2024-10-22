#
# @lc app=leetcode id=154 lang=python3
#
# [154] Find Minimum in Rotated Sorted Array II
#

# @lc code=start
class Solution:
    def findMin(self, nums: List[int]) -> int:
        # 1. Initialize pointers for binary search: left at the start, right at the end of the array.
        left, right = 0, len(nums) - 1
        
        # 2. Perform binary search as long as the left pointer is less than the right pointer.
        while left < right:
            mid = (left + right) // 2  # 3. Find the middle index of the current subarray.
            
            # 4. If the mid element is less than the rightmost element, this means the minimum is in the left part.
            if nums[mid] < nums[right]:
                right = mid
            # 5. If the mid element is greater than the rightmost element, this means the minimum is in the right part.
            elif nums[mid] > nums[right]:
                left = mid + 1
            # 6. If nums[mid] == nums[right], we can't be certain, so reduce the right pointer by 1.
            else:
                right -= 1
        
        # 7. When the loop exits, the left pointer will be at the minimum element.
        return nums[left]

# @lc code=end

