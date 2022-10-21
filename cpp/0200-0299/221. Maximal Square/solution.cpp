class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size(), maxStride = 0;
        
        // Use a size of (rows+1, cols+1) to avoid being out of bound.
        vector<vector<int>> dp(rows+1, vector<int>(cols+1, 0));
        
        // Recurrence equation:
        //  dp[r][c] = min(dp[r-1][c], dp[r][c-1], dp[r-1][c-1]) + 1;
        // For each position with a 1, we check:
        //  (1) the maximum stride we can get from the top dp[r-1][c]
        //  (2) the maximum stride we can get from the left dp[r][c-1]
        //  (3) the maximum stride we can get from the diagonal dp[r-1][c-1]
        for (int r = 1; r <= rows; ++r) {
            for (int c = 1; c <= cols; ++c) {
                if (matrix[r-1][c-1] == '1') {
                    dp[r][c] = min(dp[r-1][c], min(dp[r][c-1], dp[r-1][c-1])) + 1;
                    maxStride = max(maxStride, dp[r][c]);
                }
            }
        }
        // For example, given the following 3x3 matrix
        //  1 1 1
        //  1 1 1
        //  1 1 1 < current position
        // The dp will be
        //  1 1 1
        //  1 2 2
        //  1 2 3 < min(2, 2, 2) + 1 = 3
        // However, if r = 2, c = 1 were 0
        //  1 1 1
        //  1 1 1
        //  1 0 1 < current position
        // The dp will become
        //  1 1 1
        //  1 2 2
        //  1 0 1 < min(0, 2, 2) + 1 = 1
        return maxStride * maxStride;
    }
};