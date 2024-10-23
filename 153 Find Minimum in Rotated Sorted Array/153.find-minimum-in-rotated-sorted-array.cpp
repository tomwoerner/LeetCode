/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        // 1. Initialize two pointers: left at the start and right at the end of the array
        int left = 0, right = nums.size() - 1;
        
        // 2. Loop until left meets right
        while (left < right) {
            // 3. Calculate the middle index
            int mid = left + (right - left) / 2;
            
            // 4. If the middle element is greater than the rightmost element,
            //    the minimum is in the right half (after mid), move left pointer to mid + 1
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            }
            // 5. Otherwise, the minimum is in the left half (or at mid), move the right pointer to mid
            else {
                right = mid;
            }
        }
        
        // 6. After the loop, left will be pointing to the minimum element
        return nums[left];
    }
};
// @lc code=end

