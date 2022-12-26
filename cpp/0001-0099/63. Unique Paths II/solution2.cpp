class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(2, vector<int>(n+1, 0));
        
        // Base case: There are ony one way to reach
        // every position if the grid has only one row.
        // Stop if ot encounters an obstacle.
        for (int j = 1; j <= n && obstacleGrid[0][j-1] == 0; ++j)
            dp[0][j] = 1;

        // Recurrence: The number of ways it can reach 
        // any position other than the first row, is the
        // sum of ways comining from the top and left
        //  dp[i, j] = dp[i-1, j] + dp[i, j-1]
        // If there is an obstacle, skip it.
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (obstacleGrid[i][j-1] == 0)
                    dp[1][j] = dp[0][j] + dp[1][j-1];
                else
                    // Explicitly set positions with 
                    // obstacle to 0 as it may contain
                    // the path count from the previous
                    // iteration.
                    dp[1][j] = 0;
            }
            swap(dp[0], dp[1]);
        }
        
        return dp[0][n];
    }
};