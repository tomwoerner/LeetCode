/*
 * @lc app=leetcode id=164 lang=cpp
 *
 * [164] Maximum Gap
 */

// @lc code=start
class Solution {
public:
    int maximumGap(std::vector<int>& nums) {
        // 1. If the array contains less than two elements, return 0 as there is no gap
        if (nums.size() < 2) {
            return 0;
        }

        // 2. Find the minimum and maximum elements in the array
        int min_num = *std::min_element(nums.begin(), nums.end());
        int max_num = *std::max_element(nums.begin(), nums.end());

        // 3. Calculate the size of the buckets and initialize empty buckets
        int n = nums.size();
        int bucket_size = std::max(1, (max_num - min_num) / (n - 1));
        int bucket_count = (max_num - min_num) / bucket_size + 1;
        std::vector<std::pair<int, int>> buckets(bucket_count, {INT_MAX, INT_MIN});

        // 4. Place each number in the corresponding bucket
        for (int num : nums) {
            if (num == min_num || num == max_num) {
                continue;  // Skip the min and max elements
            }
            int bucket_index = (num - min_num) / bucket_size;
            buckets[bucket_index].first = std::min(buckets[bucket_index].first, num);
            buckets[bucket_index].second = std::max(buckets[bucket_index].second, num);
        }

        // 5. Calculate the maximum gap by comparing the min of a bucket to the max of the previous non-empty bucket
        int max_gap = 0, previous_max = min_num;
        for (const auto& bucket : buckets) {
            if (bucket.first == INT_MAX) {
                continue;  // Skip empty buckets
            }
            max_gap = std::max(max_gap, bucket.first - previous_max);
            previous_max = bucket.second;
        }

        // 6. Finally, compare the max of the last bucket with the global max_num
        max_gap = std::max(max_gap, max_num - previous_max);

        return max_gap;
    }
};
// @lc code=end

