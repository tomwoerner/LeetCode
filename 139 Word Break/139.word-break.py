#
# @lc app=leetcode id=139 lang=python3
#
# [139] Word Break
#

# @lc code=start
from typing import List

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        # 1. Create a set for quick lookup of dictionary words.
        wordSet = set(wordDict)
        
        # 2. Initialize a DP array where dp[i] is True if s[0:i] can be segmented.
        dp = [False] * (len(s) + 1)
        dp[0] = True  # Empty string can be segmented.
        
        # 3. Fill the DP array.
        for i in range(1, len(s) + 1):
            for j in range(i):
                # 4. Check if substring s[j:i] is in wordSet and s[0:j] is segmentable.
                if dp[j] and s[j:i] in wordSet:
                    dp[i] = True
                    break  # Early exit for optimization.
        
        # 5. Return whether the entire string can be segmented.
        return dp[len(s)]
 
# @lc code=end

