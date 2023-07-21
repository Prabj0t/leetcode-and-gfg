class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.size();

        // Step 1: Read in and ignore any leading whitespace.
        while (i < n && s[i] == ' ')
            i++;

        // Step 2: Check if the next character is '-' or '+', if present.
        bool neg = false;
        if (i < n && (s[i] == '-' || s[i] == '+')) {
            neg = s[i] == '-';
            i++;
        }

        // Step 3: Read in next characters until the next non-digit character or end of input.
        int result = 0;
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            // Step 5: Check for overflow before updating the result.
            if (result > (INT_MAX - digit) / 10) {
                return neg ? INT_MIN : INT_MAX;
            }

            result = result * 10 + digit;
            i++;
        }

        // Step 4: Change the sign if necessary.
        if (neg)
            result = -result;

        return result;
    }
};