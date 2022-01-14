class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        const int maxBound = INT_MAX / 10, minBound = INT_MIN / 10;
        while (x != 0) {
            int d = x % 10;
            x /= 10;
            // Determine whether rev * 10 will cause an overflow
            if (rev > maxBound || (rev == maxBound && d > 7))
                return 0;
            if (rev < minBound || (rev == minBound && d < -8))
                return 0;
            rev = rev * 10 + d;
        }
        return rev;
    }
};