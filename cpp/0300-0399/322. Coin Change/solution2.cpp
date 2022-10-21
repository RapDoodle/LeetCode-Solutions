class Solution {
public:
    /* Dynamic programming (Knapsack-like solution) */
    int coinChange(vector<int>& coins, int amount) {
        // Please note that this solution is slower than the
        // first solution. It only demonstrates how this
        // problem can be converted to a Knapsack-like problem
        int m = coins.size(), n = amount;
        vector<vector<int>> dp(m, vector<int>(n+1, amount+1));
        
        for (int i = 0; i < m; ++i) {
            dp[i][0] = 0;
            for (int j = 1; j <= n; ++j) {
                if (j >= coins[i])
                    // Can reduce the total amount with coin[i]
                    dp[i][j] = min(dp[i][j], dp[i][j-coins[i]]+1);
                if (i >= 1)
                    // Without using coin[i]
                    dp[i][j] = min(dp[i][j], dp[i-1][j]);
            }
        }
        
        return (dp[m-1][n] == amount+1) ? -1 : dp[m-1][n];
    }
};