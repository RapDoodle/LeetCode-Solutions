class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

        // Base case: elements with only one row does not flow
        for (int c = 0; c < n; ++c)
            dp[0][c] = grid[0][c];

        // Recurrence: 
        //  dp[r, c] = min(dp[r-1, 1], dp[r-1, ...], dp[r-1, k],
        //                 dp[r-1, ...], dp[r-1, n-1]) + matrix[r][c]
        //  where k != c
        for (int r = 1; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                for (int k = 0; k < n; ++k) {
                    if (k != c)
                        dp[r][c] = min(dp[r][c], dp[r-1][k]);
                }
                dp[r][c] += grid[r][c];
            }
        }

        // Find the minimum sum in the last row
        int minSum = INT_MAX;
        for (int c = 0; c < n; ++c)
            minSum = min(minSum, dp[n-1][c]);

        return minSum;

        // A more memory-efficient algorithm can be found in solution2.cpp
    }
};