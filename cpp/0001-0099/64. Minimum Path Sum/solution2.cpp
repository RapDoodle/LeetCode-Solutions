class Solution {
public:
    /* Dynamic programming */
    int minPathSum(vector<vector<int>>& grid) {
        // The recurrence:
        //  dp[r][c] = min(dp[r][c-1], dp[r-1][c]) + grid[r][c] 
        int m = grid.size(), n = grid[0].size();
        vector<int> dp(n, 0);
        
        // For the rows in [0..m], and columns in [0..n]
        // Note: Because we compressed the 2D DP matrix into
        // a 1D matrix, as we iterate through each row, every
        // element to the left of the current position belong
        // to the current row. The current position (before 
        // assignment) and indexes to the right belong to the 
        // previous row.
        for (int r = 0; r < m; ++r)
            for (int c = 0; c < n; ++c)
                if (r == 0 && c == 0)
                    dp[c] = grid[0][0];
                else if (r == 0)
                    dp[c] = dp[c-1] + grid[0][c];
                else if (c == 0)
                    dp[0] = dp[0] + grid[r][0];
                else
                    dp[c] = min(dp[c-1], dp[c]) + grid[r][c];
        
        return dp[n-1];
    }
};