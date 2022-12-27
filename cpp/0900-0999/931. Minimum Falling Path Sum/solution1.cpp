class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Base case: elements with only one row does not flow
        for (int c = 0; c < n; ++c)
            dp[0][c] = matrix[0][c];

        // Recurrence: 
        //  dp[r, c] = min(dp[r-1, c], dp[r-1, c-1], 
        //                 dp[r-1, c+1]) + matrix[r][c]
        for (int r = 1; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                // 1. fall from top 
                dp[r][c] = dp[r-1][c];
                
                // 2. fall from upper-left
                if (c > 0)
                    dp[r][c] = min(dp[r][c], dp[r-1][c-1]);
                
                // 3. fall from upperr-right
                if (c < n-1)
                    dp[r][c] = min(dp[r][c], dp[r-1][c+1]);
                
                // Sum with the current entry
                dp[r][c] += matrix[r][c];
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