/*
 * @lc app=leetcode id=168 lang=cpp
 *
 * [168] Excel Sheet Column Title
 */

// @lc code=start
#include <string>

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result = "";  // 1. Initialize an empty string to store the result
        
        while (columnNumber > 0) {  // 2. Loop until columnNumber is reduced to 0
            int remainder = columnNumber % 26;  // 3. Find the remainder (corresponding to a letter)
            
            if (remainder == 0) {  // 4. If remainder is 0, it means 'Z'
                result = 'Z' + result;  // 5. Append 'Z' to the result
                columnNumber = (columnNumber / 26) - 1;  // 6. Reduce columnNumber by dividing by 26 and adjusting
            } else {
                result = char(remainder + 'A' - 1) + result;  // 7. Convert remainder to corresponding letter and prepend to result
                columnNumber /= 26;  // 8. Update columnNumber by dividing by 26
            }
        }
        
        return result;  // 9. Return the final result
    }
};

// @lc code=end

