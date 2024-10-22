/*
 * @lc app=leetcode id=165 lang=cpp
 *
 * [165] Compare Version Numbers
 */

// @lc code=start
#include <vector>
#include <string>
#include <sstream>
#include <iostream>

class Solution {
public:
    int compareVersion(string version1, string version2) {
        // 1. Split both version strings into vectors of integers by the '.' delimiter
        vector<int> v1 = split(version1);
        vector<int> v2 = split(version2);

        // 2. Determine the maximum length of the two version vectors
        int max_len = max(v1.size(), v2.size());

        // 3. Iterate through the revisions of both versions
        for (int i = 0; i < max_len; i++) {
            // 4. Get the current revision number for each version or use 0 if index exceeds size
            int r1 = i < v1.size() ? v1[i] : 0;
            int r2 = i < v2.size() ? v2[i] : 0;

            // 5. Compare the current revisions
            if (r1 < r2) {
                return -1;  // version1 < version2
            } else if (r1 > r2) {
                return 1;  // version1 > version2
            }
        }

        // 6. If all revisions are equal, return 0 (versions are equal)
        return 0;
    }

private:
    // Utility function to split a version string by '.' and return vector of integers
    vector<int> split(const string& version) {
        vector<int> result;
        stringstream ss(version);
        string token;
        
        // Split by '.' and convert each part to an integer
        while (getline(ss, token, '.')) {
            result.push_back(stoi(token));
        }

        return result;
    }
};
// @lc code=end

