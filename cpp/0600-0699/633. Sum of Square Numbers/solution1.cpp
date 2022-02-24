class Solution {
public:
    /* Improved brute-force */
    bool judgeSquareSum(int c) {
        // When b = 0, we have a^2 = c. Thus, the maximum
        // number allowed for a is a <= sqrt(c) 
        int maxA = sqrt(c);
        for (int a = 0; a <= maxA; ++a) {
            // b can be estimated using 
            // b = sqrt(c - a^2)
            int b = sqrt(c - a*a);
            
            // When a valid pair is found
            if (a*a + b*b == c)
                return true;
        }
        return false;
    }
};