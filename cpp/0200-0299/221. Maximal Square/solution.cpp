class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size(), maxSide = 0;
        
        // Use a size of (rows+1, cols+1) to avoid being out of bound.
        vector<vector<int>> dp(rows+1, vector<int>(cols+1, 0));
        
        // Transfer function:
        //  dp[r][c] = min(dp[r-1][c], dp[r][c-1], dp[r-1][c-1]) + 1;
        for (int r = 1; r <= rows; ++r) {
            for (int c = 1; c <= cols; ++c) {
                if (matrix[r-1][c-1] == '1') {
                    dp[r][c] = min(dp[r-1][c], min(dp[r][c-1], dp[r-1][c-1])) + 1;
                    maxSide = max(maxSide, dp[r][c]);
                }
            }
        }
        return maxSide * maxSide;
    }
};