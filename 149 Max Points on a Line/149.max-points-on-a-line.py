#
# @lc app=leetcode id=149 lang=python3
#
# [149] Max Points on a Line
#

# @lc code=start
from collections import defaultdict
from typing import List
from math import gcd

class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        # 1. Handle edge cases: If there are 0 or 1 points, return the number of points.
        if len(points) <= 2:
            return len(points)

        max_points = 0  # Initialize the maximum points on a line.

        # 2. Loop through each point and calculate the slope with every other point.
        for i in range(len(points)):
            slopes = defaultdict(int)  # Dictionary to store slopes and their counts.
            x1, y1 = points[i]

            for j in range(len(points)):
                if i != j:  # Avoid comparing the same point.
                    x2, y2 = points[j]
                    dx = x2 - x1  # Change in x
                    dy = y2 - y1  # Change in y

                    # 3. Reduce the slope by using the greatest common divisor (gcd).
                    if dx == 0:  # Vertical line case
                        slope = ('inf', y1)  # Use 'inf' for vertical lines
                    elif dy == 0:  # Horizontal line case
                        slope = (x1, 'inf')  # Use 'inf' for horizontal lines
                    else:
                        g = gcd(dy, dx)  # Get the gcd to simplify the slope
                        slope = (dy // g, dx // g)  # Store the reduced slope

                    slopes[slope] += 1  # Increment the count of this slope

            # Get the maximum count of points for any slope from the current point
            max_points_on_line = max(slopes.values(), default=0) + 1  # +1 for the starting point
            max_points = max(max_points, max_points_on_line)

        return max_points  # Return the overall maximum points on a line.

# Example usage:
'''
solution = Solution()
points = [[1, 1], [2, 2], [3, 3]]
print(solution.maxPoints(points))  # Output: 3
'''

# @lc code=end

