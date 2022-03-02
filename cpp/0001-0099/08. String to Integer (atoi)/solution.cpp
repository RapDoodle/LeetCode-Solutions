class Solution {
public:
    int myAtoi(string s) {
        int m = s.length();
        int sPtr = 0;
        int sign = 1;

        // Look for white spaces
        while (s[sPtr] != '\0' && s[sPtr] == ' ')
            ++sPtr;

        // Look for + or -
        if (s[sPtr] != '\0' && (s[sPtr] == '-' || s[sPtr] == '+')) {
            if (s[sPtr] == '-') {
                sign = -1;
            }
            ++sPtr;
        }

        int ans = 0;
        const int maxBound = INT_MAX / 10, minBound = INT_MIN / 10;
        while (s[sPtr] >= 48 && s[sPtr] <= 57) {
            int d = s[sPtr] - 48;
            if (sign == 1 && (ans > maxBound || (ans == maxBound && d > 7)))
                return INT_MAX;
            if (sign == -1 && (ans < minBound || (ans == minBound && d > 8)))
                return INT_MIN;
            ans = (ans * 10) + d * sign;
            ++sPtr;
        }

        return ans;
    }
};