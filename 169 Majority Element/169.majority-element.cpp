/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // 1. Initialize two variables:
        //    - candidate: to store the potential majority element.
        //    - count: to keep track of the number of times the candidate element appears.
        int candidate = 0;
        int count = 0;

        // 2. Iterate through each element in the nums array.
        for (int num : nums) {
            // 3. If the count is 0, this means we need a new candidate.
            //    Set the current element as the new candidate.
            if (count == 0) {
                candidate = num;
            }

            // 4. Update the count:
            //    - If the current element is the same as the candidate, increment the count.
            //    - If it is different, decrement the count.
            if (num == candidate) {
                count++;
            } else {
                count--;
            }
        }

        // 5. After the loop ends, the candidate will be the majority element,
        //    because the majority element appears more than n / 2 times.
        return candidate;
    }
};

// @lc code=end

