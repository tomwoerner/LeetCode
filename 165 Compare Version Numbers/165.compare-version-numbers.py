#
# @lc app=leetcode id=165 lang=python3
#
# [165] Compare Version Numbers
#

# @lc code=start
class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        # 1. Split both version strings into lists of integers by the '.' delimiter
        v1 = list(map(int, version1.split('.')))
        v2 = list(map(int, version2.split('.')))

        # 2. Determine the maximum length of the two version lists
        max_len = max(len(v1), len(v2))

        # 3. Iterate through the revisions of both versions
        for i in range(max_len):
            # 4. Get the current revision number for each version or use 0 if index exceeds length
            r1 = v1[i] if i < len(v1) else 0
            r2 = v2[i] if i < len(v2) else 0

            # 5. Compare the current revisions
            if r1 < r2:
                return -1  # version1 < version2
            elif r1 > r2:
                return 1  # version1 > version2

        # 6. If all revisions are equal, return 0 (versions are equal)
        return 0
# @lc code=end

