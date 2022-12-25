class Solution {
private:
    /* DFS + Caching */
    int dfs(int i, int j, vector<vector<int>>& dp,
            const vector<vector<int>>& matrix, 
            const int m, const int n) {
        // If it has been visited, simiply return the cached value
        // Note: Initially, all values are 0. Once visited, dp[i][j]
        // will be at least 1.
        if (dp[i][j] > 0)
            return dp[i][j];
        
        // Boundary condition
        int maxPathLen = 1;

        // Check whether going up is possible
        if (i - 1 >= 0 && matrix[i-1][j] > matrix[i][j])
            maxPathLen = max(maxPathLen, dfs(i-1, j, dp, matrix, m, n) + 1);

        // Check whether going down is possible
        if (i + 1 < m  && matrix[i+1][j] > matrix[i][j])
            maxPathLen = max(maxPathLen, dfs(i+1, j, dp, matrix, m, n) + 1);

        // Check whether going left is possible
        if (j - 1 >= 0 && matrix[i][j-1] > matrix[i][j])
            maxPathLen = max(maxPathLen, dfs(i, j-1, dp, matrix, m, n) + 1);

        // Check whether going right is possible
        if (j + 1 < n && matrix[i][j+1] > matrix[i][j])
            maxPathLen = max(maxPathLen, dfs(i, j+1, dp, matrix, m, n) + 1);

        // Cache the result
        dp[i][j] = maxPathLen;

        return maxPathLen;
    }

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), maxLen = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // Iterate through every position
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // Skip if it has been visited
                if (dp[i][j] == 0)
                    dfs(i, j, dp, matrix, m, n);
                maxLen = max(maxLen, dp[i][j]);
            }
        }
        return maxLen;
    }
};