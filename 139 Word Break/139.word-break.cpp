/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // 1. Create a hash set for quick lookup of dictionary words.
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        
        // 2. Initialize a DP array where dp[i] is true if s[0:i] can be segmented.
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true; // Empty string can be segmented.
        
        // 3. Fill the DP array.
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                // 4. Check if substring s[j:i] is in wordSet and s[0:j] is segmentable.
                if (dp[j] && wordSet.find(s.substr(j, i - j)) != wordSet.end()) {
                    dp[i] = true;
                    break; // Early exit for optimization.
                }
            }
        }
        
        // 5. Return whether the entire string can be segmented.
        return dp[s.size()];
    }
};
// @lc code=end

