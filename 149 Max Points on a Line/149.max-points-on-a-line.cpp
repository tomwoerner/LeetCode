/*
 * @lc app=leetcode id=149 lang=cpp
 *
 * [149] Max Points on a Line
 */

// @lc code=start
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <iostream>

using std::vector;
using std::unordered_map;
using std::string;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        // 1. Handle edge case: if there are fewer than 2 points, return the number of points.
        if (points.size() < 2) return points.size();
        
        int max_points = 0;  // To store the maximum number of points on the same line.

        // 2. Iterate through each point as the starting point.
        for (int i = 0; i < points.size(); i++) {
            unordered_map<string, int> slopes;  // Map to count slopes.

            // 3. Compare the current point with all other points.
            for (int j = 0; j < points.size(); j++) {
                if (i != j) {  // Avoid comparing the point with itself.
                    int dx = points[j][0] - points[i][0];  // Difference in x-coordinates
                    int dy = points[j][1] - points[i][1];  // Difference in y-coordinates
                    
                    // Create a slope representation in reduced form.
                    string slope;
                    if (dx == 0) {
                        slope = "inf";  // Vertical line
                    } else if (dy == 0) {
                        slope = "0";  // Horizontal line
                    } else {
                        int g = std::gcd(dy, dx);  // Get the gcd for reduction
                        slope = std::to_string(dy / g) + "/" + std::to_string(dx / g);  // Reduced slope
                    }

                    slopes[slope]++;  // Count points with the same slope.
                }
            }

            // The maximum points with the same slope from point i.
            int current_max = 1;  // Start with 1 for the current point itself.
            for (const auto& pair : slopes) {
                current_max = std::max(current_max, pair.second + 1);  // +1 for the starting point itself.
            }
            max_points = std::max(max_points, current_max);  // Update the global max points.
        }

        return max_points;
    }
};

// Example usage
/*int main() {
    Solution solution;
    std::vector<std::vector<int>> points = {{1,1},{2,2},{3,3}};
    std::cout << solution.maxPoints(points) << std::endl;  // Output: 3
    return 0;
}*/

// @lc code=end

