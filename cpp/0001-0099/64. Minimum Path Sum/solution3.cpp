class Solution {
public:
    /* Dynamic programming */
    int minPathSum(vector<vector<int>>& grid) {
        // The recurrence:
        //  dp[r][c] = min(dp[r][c-1], dp[r-1][c]) + grid[r][c] 
        int m = grid.size(), n = grid[0].size();

        // Modify everything inplace (kind of cheating)
        // First row
        for (int j = 1; j < n; ++j)
            grid[0][j] += grid[0][j-1];

        // First column
        for (int i = 1; i < m; ++i)
            grid[i][0] += grid[i-1][0];
        
        for (int i = 1; i < m; ++i)
            for (int j = 1; j < n; ++j)
                grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
        
        return grid[m-1][n-1];
    }
};