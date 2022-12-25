class Solution {
private:
    const int MODULO = 1e9 + 7;

    /* DFS + Caching */
    int dfs(int i, int j, vector<vector<int>>& dp,
            const vector<vector<int>>& grid, 
            const int m, const int n) {
        // If it has been visited, simiply return the cached value
        // Note: Initially, all values are 0. Once visited, dp[i][j]
        // will be at least 1.
        if (dp[i][j] > 0)
            return dp[i][j];
        
        // Boundary condition: Path of length 1
        int numPaths = 1;

        // Check whether going up is possible
        if (i - 1 >= 0 && grid[i-1][j] > grid[i][j])
            numPaths = (numPaths + dfs(i-1, j, dp, grid, m, n)) % MODULO;

        // Check whether going down is possible
        if (i + 1 < m  && grid[i+1][j] > grid[i][j])
            numPaths = (numPaths + dfs(i+1, j, dp, grid, m, n)) % MODULO;

        // Check whether going left is possible
        if (j - 1 >= 0 && grid[i][j-1] > grid[i][j])
            numPaths = (numPaths + dfs(i, j-1, dp, grid, m, n)) % MODULO;

        // Check whether going right is possible
        if (j + 1 < n && grid[i][j+1] > grid[i][j])
            numPaths = (numPaths + dfs(i, j+1, dp, grid, m, n)) % MODULO;

        // Cache the result
        dp[i][j] = numPaths;

        return numPaths;
    }

public:
    int countPaths(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), numPaths = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // Iterate through every position
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                numPaths = (numPaths + dfs(i, j, dp, grid, m, n)) % MODULO;
        
        return numPaths;
    }
};