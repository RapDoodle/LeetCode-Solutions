class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(2, vector<int>(n, 0));

        // Special case: 1*1 matrix
        if (n == 1)
            return matrix[0][0];

        // Base case: elements with only one row does not flow
        for (int c = 0; c < n; ++c)
            dp[0][c] = matrix[0][c];

        // Recurrence: 
        //  dp[r, c] = min(dp[r-1, c], dp[r-1, c-1], 
        //                 dp[r-1, c+1]) + matrix[r][c]
        for (int r = 1; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                // 1. fall from top 
                dp[1][c] = dp[0][c];
                
                // 2. fall from upper-left
                if (c > 0)
                    dp[1][c] = min(dp[1][c], dp[0][c-1]);
                
                // 3. fall from upperr-right
                if (c < n-1)
                    dp[1][c] = min(dp[1][c], dp[0][c+1]);
                
                // Sum with the current entry
                dp[1][c] += matrix[r][c];
            }

            swap(dp[0], dp[1]);
        }

        // Find the minimum sum in the last row
        int minSum = INT_MAX;
        for (int c = 0; c < n; ++c)
            minSum = min(minSum, dp[0][c]);

        return minSum;
    }
};