class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX-1));

        // First pass: initialization and find from top and left
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                // Initialization
                dp[r][c] = (grid[r][c] ? 0 : INT_MAX-1);

                // Skip when the current grid is an island
                if (grid[r][c] == 1)
                    continue;
                if (r-1 >= 0)
                    dp[r][c] = min(dp[r][c], dp[r-1][c]+1);
                if (c-1 >= 0)
                    dp[r][c] = min(dp[r][c], dp[r][c-1]+1);
            }
        }

        // Second pass: bottom and right and find the maximum
        // distance
        int maxDist = INT_MIN;
        for (int r = n-1; r >= 0; --r) {
            for (int c = n-1; c >= 0; --c) {
                // Skip when the current grid is an island
                if (grid[r][c] == 1)
                    continue;
                if (r+1 < n)
                    dp[r][c] = min(dp[r][c], dp[r+1][c]+1);
                if (c+1 < n)
                    dp[r][c] = min(dp[r][c], dp[r][c+1]+1);
                maxDist = max(maxDist, dp[r][c]);
            }
        }

        return (maxDist == INT_MAX-1 || maxDist == INT_MIN) ? -1 : maxDist;
    }
};