class Solution {
public:
    /* Dynamic programming */
    int climbStairs(int n) {
        if (n <= 2)
            return n;
        
        // Essentially solving:
        //  f(n) = f(n-1) + f(n-2) [Fibonacci sequence]
        vector<int> dp(n+1, 1);
        for (int i = 2; i <= n; ++i)
            dp[i] = dp[i-1] + dp[i-2];
        return dp[n];
        
        // See a much more memory efficient solution
        // in solution2.cpp
    }
};