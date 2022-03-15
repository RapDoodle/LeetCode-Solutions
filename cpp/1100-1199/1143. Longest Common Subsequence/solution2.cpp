class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length(), n = text2.length();
        
        // Only two rows are used
        vector<vector<int>> dp(2, vector<int>(n+1, 0));
        
        // Exhaustively search for the length of the longest
        // subsequence in text1[0, i-1] and text2[0, j-1],
        // where i in [1, m] and j in [1, n].
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (text1[i-1] == text2[j-1])
                    // When there is a match, increment the
                    // count based on the two strings' longest
                    // common sequence length without the 
                    // current matching character.
                    dp[1][j] = dp[0][j-1] + 1;
                else
                    // Not a match, simply be the maximum common
                    // subsequence length without the (i-1)-th
                    // index in text1 or the (j-1)-th index in
                    // text2.
                    dp[1][j] = max(dp[0][j], dp[1][j-1]);
            }
            swap(dp[0], dp[1]);
        }
        
        return dp[0][n];
    }
};