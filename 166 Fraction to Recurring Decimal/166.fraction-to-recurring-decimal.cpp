/*
 * @lc app=leetcode id=166 lang=cpp
 *
 * [166] Fraction to Recurring Decimal
 */

// @lc code=start
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        // 1. Handle zero numerator case
        if (numerator == 0) {
            return "0";
        }
        
        // 2. Handle sign of the result
        string sign = ((numerator < 0) ^ (denominator < 0)) ? "-" : "";
        
        // 3. Work with absolute values for ease of calculation
        long num = abs(static_cast<long>(numerator));
        long den = abs(static_cast<long>(denominator));
        
        // 4. Integer part of the result
        long integer_part = num / den;
        
        // 5. Initialize the result with the integer part and handle decimal part
        string result = sign + to_string(integer_part);
        
        // 6. Calculate the remainder for the decimal part
        long remainder = num % den;
        if (remainder == 0) {
            return result; // 7. Return if no decimal part exists
        }
        
        result += '.'; // 8. Add decimal point to the result
        unordered_map<long, int> remainder_map; // 9. Map to store seen remainders and their positions
        string decimal_part; // 10. Initialize decimal part
        
        while (remainder != 0) {
            // 11. If the remainder has been seen, a repeating decimal is detected
            if (remainder_map.find(remainder) != remainder_map.end()) {
                int index = remainder_map[remainder]; // 12. Get the index of the start of the repeat
                decimal_part.insert(index, "("); // 13. Enclose the repeating part
                decimal_part += ")";
                break;
            }
            
            // 14. Record the position of the current remainder
            remainder_map[remainder] = decimal_part.length();
            remainder *= 10; // 15. Scale up the remainder
            long decimal_digit = remainder / den; // 16. Calculate the next digit
            decimal_part += to_string(decimal_digit); // 17. Append digit to decimal part
            remainder %= den; // 18. Update the remainder
        }

        return result + decimal_part; // 19. Return the complete result
    }
};
// @lc code=end

