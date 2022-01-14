class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x != 0 && x % 10 == 0))
            return false;
        // Only compare half the integers
        // This avoids overflow
        int r = 0;
        // Only positive integers can go this far
        while (x > r) {
            r = (r * 10) + (x % 10);
            x /= 10;
        }
        return (r == x) || ((r / 10) == x);
    }
};