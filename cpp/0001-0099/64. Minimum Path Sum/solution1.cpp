class Solution {
public:
    /* Dynamic programming */
    int minPathSum(vector<vector<int>>& grid) {
        // The recurrence:
        //  dp[r][c] = min(dp[r][c-1], dp[r-1][c]) + grid[r][c] 
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = grid[0][0];
        
        // For the first row, each grid can only be reached
        // through moving right.
        for (int c = 1; c < n; ++c)
            dp[0][c] = dp[0][c-1] + grid[0][c];
        
        // For the first row, each grid can only be reached
        // through moving down.
        for (int r = 1; r < m; ++r)
            dp[r][0] = dp[r-1][0] + grid[r][0];
        
        // For the rows in [1..m], and columns in [1..n]
        for (int r = 1; r < m; ++r)
            for (int c = 1; c < n; ++c)
                dp[r][c] = min(dp[r][c-1], dp[r-1][c]) + grid[r][c];
        
        return dp[m-1][n-1];
        
        // A more memory-efficient solution can be found in solution2.cpp
    }
};