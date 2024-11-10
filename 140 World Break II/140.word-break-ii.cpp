/*
 * @lc app=leetcode id=140 lang=cpp
 *
 * [140] Word Break II
 */

// @lc code=start
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        // 1. Convert wordDict to an unordered_set for O(1) average-time lookups
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());

        // 2. Memoization map to store results of subproblems
        unordered_map<int, vector<string>> memo;

        // 3. Define a recursive helper function
        function<vector<string>(int)> backtrack = [&](int start) {
            // 4. If the current start index is at the end of the string, return a vector with an empty string
            if (start == s.size()) return vector<string>{""};

            // 5. If the result for this start index is already computed, return it from memo
            if (memo.count(start)) return memo[start];

            // 6. Initialize a vector to store all valid sentences starting from this index
            vector<string> sentences;

            // 7. Iterate over the end index of the substring
            for (int end = start + 1; end <= s.size(); ++end) {
                // 8. Extract the substring from start to end
                string word = s.substr(start, end - start);

                // 9. If the word is in the dictionary, recursively process the remaining string
                if (wordSet.count(word)) {
                    // 10. Get all sentences from the remaining substring
                    vector<string> sub_sentences = backtrack(end);

                    // 11. Combine the current word with each sub_sentence
                    for (const string& sub_sentence : sub_sentences) {
                        if (!sub_sentence.empty()) {
                            sentences.push_back(word + " " + sub_sentence);
                        } else {
                            sentences.push_back(word);
                        }
                    }
                }
            }

            // 12. Store the result in memo and return it
            memo[start] = sentences;
            return sentences;
        };

        // 13. Call the helper function starting from index 0
        return backtrack(0);
    }
};

// @lc code=end

