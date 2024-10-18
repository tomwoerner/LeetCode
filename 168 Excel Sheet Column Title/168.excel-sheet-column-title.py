#
# @lc app=leetcode id=168 lang=python3
#
# [168] Excel Sheet Column Title
#

# @lc code=start
class Solution:
    def convertToTitle(self, columnNumber: int) -> str:
        result = ""  # 1. Initialize an empty string to store the result
    
        while columnNumber > 0:  # 2. Loop until columnNumber is reduced to 0
            remainder = columnNumber % 26  # 3. Find the remainder (corresponding to a letter)
        
            if remainder == 0:  # 4. If remainder is 0, it means 'Z'
                result = 'Z' + result  # 5. Append 'Z' to the result
                columnNumber = (columnNumber // 26) - 1  # 6. Reduce columnNumber by dividing by 26 and adjusting
            else:
                result = chr(remainder + ord('A') - 1) + result  # 7. ASCII conversion remainder and prepend to result
                columnNumber //= 26  # 8. Update columnNumber by dividing by 26
    
        return result  # 9. Return the final result
# @lc code=end

