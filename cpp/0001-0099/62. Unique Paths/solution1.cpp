class Solution {
public:
    int uniquePaths(int m, int n) {
        // Special case: Only one row
        if (m == 1)
            return 1;
        
        vector<vector<int>> dp(m, vector<int>(n+1, 0));
        
        // Base case: There are ony one way to reach
        // every position if the grid has only one row
        for (int j = 1; j <= n; ++j)
            dp[0][j] = 1;

        // Recurrence: The number of ways it can reach 
        // any position other than the first row, is the
        // sum of ways comining from the top and left
        //  dp[i, j] = dp[i-1, j] + dp[i, j-1]
        for (int i = 1; i < m; ++i)
            for (int j = 1; j <= n; ++j)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
        
        return dp[m-1][n];

        // A more memory efficient algorithm can be found
        // in solution2.cpp
    }
};