#
# @lc app=leetcode id=164 lang=python3
#
# [164] Maximum Gap
#

# @lc code=start
class Solution:
    def maximumGap(self, nums: List[int]) -> int:
        # 1. If the array contains less than two elements, return 0 as there is no gap
        if len(nums) < 2:
            return 0
        
        # 2. Find the minimum and maximum elements in the array
        min_num, max_num = min(nums), max(nums)
        
        # 3. Calculate the size of the buckets and initialize empty buckets
        n = len(nums)
        bucket_size = max(1, (max_num - min_num) // (n - 1))
        bucket_count = (max_num - min_num) // bucket_size + 1
        buckets = [[None, None] for _ in range(bucket_count)]  # Each bucket stores [min_value, max_value]

        # 4. Place each number in the corresponding bucket
        for num in nums:
            if num == min_num or num == max_num:
                continue  # Skip the min and max elements
            bucket_index = (num - min_num) // bucket_size
            if buckets[bucket_index][0] is None:
                buckets[bucket_index][0] = buckets[bucket_index][1] = num
            else:
                buckets[bucket_index][0] = min(buckets[bucket_index][0], num)
                buckets[bucket_index][1] = max(buckets[bucket_index][1], num)

        # 5. Calculate the maximum gap by comparing the min of a bucket to the max of the previous non-empty bucket
        max_gap, previous_max = 0, min_num
        for bucket_min, bucket_max in buckets:
            if bucket_min is None:
                continue  # Skip empty buckets
            max_gap = max(max_gap, bucket_min - previous_max)
            previous_max = bucket_max

        # 6. Finally, compare the max of the last bucket with the global max_num
        max_gap = max(max_gap, max_num - previous_max)

        return max_gap

# @lc code=end

