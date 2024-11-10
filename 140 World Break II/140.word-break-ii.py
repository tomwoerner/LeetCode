#
# @lc app=leetcode id=140 lang=python3
#
# [140] Word Break II
#

# @lc code=start
from typing import List

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        # 1. Convert wordDict to a set for O(1) average-time lookups
        word_set = set(wordDict)
        
        # 2. Memoization dictionary to store results of subproblems
        memo = {}

        # 3. Define a recursive helper function
        def backtrack(start):
            # 4. If the current start index is at the end of the string, return an empty list
            if start == len(s):
                return [""]

            # 5. If the result for this start index is already computed, return it from memo
            if start in memo:
                return memo[start]

            # 6. Initialize a list to store all valid sentences starting from this index
            sentences = []

            # 7. Iterate over the end index of the substring
            for end in range(start + 1, len(s) + 1):
                # 8. Extract the substring from start to end
                word = s[start:end]

                # 9. If the word is in the dictionary, recursively process the remaining string
                if word in word_set:
                    # 10. Get all sentences from the remaining substring
                    for sub_sentence in backtrack(end):
                        # 11. Combine the current word with each sub_sentence
                        if sub_sentence:
                            sentences.append(word + " " + sub_sentence)
                        else:
                            sentences.append(word)

            # 12. Store the result in memo and return it
            memo[start] = sentences
            return sentences

        # 13. Call the helper function starting from index 0
        return backtrack(0)
 
# @lc code=end

