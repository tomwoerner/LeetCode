/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 */

// @lc code=start
#include <sstream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::string reverseWords(std::string s) {
        // 1. Use a stringstream to split 's' into words.
        std::istringstream iss(s);
        std::vector<std::string> words;
        std::string word;
        
        // 2. Extract each word and add it to the vector.
        while (iss >> word) {
            words.push_back(word); // <vector>
        }
        
        // 3. Reverse the vector of words.
        std::reverse(words.begin(), words.end()); // <algorithm>
        
        // 4. Concatenate words into a single string with a single space separator.
        std::ostringstream oss; // <sstream>
        for (size_t i = 0; i < words.size(); ++i) {
            if (i > 0) oss << " ";  // Add a space between words
            oss << words[i];
        }
        
        return oss.str();
    }
};

// Example usage:
/* int main() {
    Solution solution;
    std::string input_string = "  hello world  ";
    std::cout << solution.reverseWords(input_string) << std::endl;  // Output: "world hello"
    return 0;
} */

// @lc code=end

