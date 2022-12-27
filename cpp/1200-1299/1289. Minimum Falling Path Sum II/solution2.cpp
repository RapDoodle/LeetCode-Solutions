class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(2, vector<int>(n, INT_MAX));

        // Special case: 1*1 matrix
        if (n == 1)
            return grid[0][0];

        // Base case: elements with only one row does not flow
        for (int c = 0; c < n; ++c)
            dp[0][c] = grid[0][c];

        // Recurrence: 
        //  dp[r, c] = min(dp[r-1, 1], dp[r-1, ...], dp[r-1, k],
        //                 dp[r-1, ...], dp[r-1, n-1]) + matrix[r][c]
        //  where k != c
        for (int r = 1; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                dp[1][c] = INT_MAX;
                for (int k = 0; k < n; ++k) {
                    if (k != c)
                        dp[1][c] = min(dp[1][c], dp[0][k]);
                }
                dp[1][c] += grid[r][c];
            }
            swap(dp[0], dp[1]);
        }

        // Find the minimum sum in the last row
        int minSum = INT_MAX;
        for (int c = 0; c < n; ++c)
            minSum = min(minSum, dp[0][c]);

        return minSum;

        // A more memory-efficient algorithm can be found in solution2.cpp
    }
};