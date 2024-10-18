#
# @lc app=leetcode id=166 lang=python3
#
# [166] Fraction to Recurring Decimal
#

# @lc code=start
class Solution:
    def fractionToDecimal(self, numerator: int, denominator: int) -> str:
        # 1. Handle zero numerator case
        if numerator == 0:
            return "0"
        
        # 2. Handle sign of the result
        sign = '-' if (numerator < 0) ^ (denominator < 0) else ''
        
        # 3. Work with absolute values for ease of calculation
        numerator, denominator = abs(numerator), abs(denominator)
        
        # 4. Integer part of the result
        integer_part = numerator // denominator
        
        # 5. Initialize the result with the integer part and handle decimal part
        result = f"{sign}{integer_part}"
        
        # 6. Calculate the remainder for the decimal part
        remainder = numerator % denominator
        if remainder == 0:
            return result  # 7. Return if no decimal part exists
        
        result += '.'  # 8. Add decimal point to the result
        remainder_map = {}  # 9. Dictionary to store seen remainders and their positions
        decimal_part = ""  # 10. Initialize decimal part
        
        while remainder != 0:
            # 11. If the remainder has been seen, a repeating decimal is detected
            if remainder in remainder_map:
                index = remainder_map[remainder]  # 12. Get the index of the start of the repeat
                decimal_part = decimal_part[:index] + "(" + decimal_part[index:] + ")"  # 13. Enclose the repeating part
                break
            
            # 14. Record the position of the current remainder
            remainder_map[remainder] = len(decimal_part)
            remainder *= 10  # 15. Scale up the remainder
            decimal_digit = remainder // denominator  # 16. Calculate the next digit
            decimal_part += str(decimal_digit)  # 17. Append digit to decimal part
            remainder %= denominator  # 18. Update the remainder

        return result + decimal_part  # 19. Return the complete result

# @lc code=end

