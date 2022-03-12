class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, n);
        
        // We keep it here because we need to ensure when 
        // i = n, we MAY have i-j*j, resulting in 
        // n-sqrt(n)^2 = 0.
        dp[0] = 0;
        
        // For each problem, we wish to solve the least
        // number of perfect sqaure numbers that sum
        // to i, which is between 1 and n.
        for (int i = 1; i <= n; ++i)
            // To solve the subproblem, we need to find
            //  1 + min(dp[i-1], dp[1-2], dp[1-4], ...),
            // which is the number of perfect squares 
            // needed to reach the i
            for (int j = 1; j*j <= i; ++j) 
                dp[i] = min(dp[i], dp[i-j*j] + 1);
        
        return dp[n];
    }
};