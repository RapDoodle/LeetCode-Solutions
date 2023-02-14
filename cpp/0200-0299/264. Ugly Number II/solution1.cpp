class Solution {
public:
    /* Dynamic programming */
    int nthUglyNumber(int n) {
        // If it is an ugly number, it can be written as
        //  n = 2^a + 3^b + 5^c (n > 0)
        // Use three pointers. Each pointer will be
        // multiplied by 2, 3, and 5 respectively. 
        // Advance the one with the smallest product.
        vector<int> dp(n+1);
        dp[1] = 1;
        int num2, num3, num5, p2 = 1, p3 = 1, p5 = 1;
        for (int i = 2; i <= n; ++i) {
            num2 = dp[p2] * 2;
            num3 = dp[p3] * 3;
            num5 = dp[p5] * 5;
            dp[i] = min(num2, min(num3, num5));
            // num2, num3, num5 could be equal
            if (dp[i] == num2)
                ++p2;
            if (dp[i] == num3)
                ++p3;
            if (dp[i] == num5)
                ++p5;
        }
        return dp[n];
    }
};