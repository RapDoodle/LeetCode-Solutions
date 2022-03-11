class Solution {
public:
    /* Dynamic-programming */
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size(), cols = mat[0].size();
        
        // Transfer function:
        //  dp[r][c] = min(dp[r-1][c] + 1, dp[r][c-1] + 1, 
        //                 dp[r+1][c] + 1, dp[r][c+1] + 1), when mat[r][c] > 0
        //             0, when mat[r][c] = 0
        // However, searching in four directions simultaneously is not possible
        // when we need information in the direction counter to the traversal 
        // direction. Thus, we split the traversal into two phases:
        //  1. Iterate from top-left to bottom-right to find
        //      min(dp[r][c], dp[r-1][c] + 1, dp[r][c-1] + 1)
        //  2. Iterate from bottom-right to top-left to find
        //      min(dp[r][c], dp[r+1][c] + 1, dp[r][c+1] + 1)
        // Note on the reason for INT_MAX-1 in for dp's initialization:
        //  For positions like (0, 0), if it were INT_MAX, and mat[0][0] != 0,
        //  the body of the two if-statements will be ignored as r and c are
        //  both 0 at the moment. Then for position (0, 1). Because c > 0, when
        //  we try to calculate dp[r][c-1] + 1, which is dp[0][0] + 1, it causes 
        //  overflow.
        
        // Iterate from top-left to bottom-right
        vector<vector<int>> dp(rows, vector<int>(cols, INT_MAX-1));
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (mat[r][c] > 0) {
                    if (r > 0)
                        dp[r][c] = min(dp[r][c], dp[r-1][c] + 1);
                    if (c > 0)
                        dp[r][c] = min(dp[r][c], dp[r][c-1] + 1);
                } else {
                    dp[r][c] = 0;
                }
            }
        }
        
        // Iterate from bottom-right to top-left
        for (int r = rows-1; r >= 0; --r) {
            for (int c = cols-1; c >= 0; --c) {
                if (mat[r][c] > 0) {
                    if (r < rows-1)
                        dp[r][c] = min(dp[r][c], dp[r+1][c] + 1);
                    if (c < cols-1)
                        dp[r][c] = min(dp[r][c], dp[r][c+1] + 1);
                }
            }
        } 
        
        return dp;
    }
};