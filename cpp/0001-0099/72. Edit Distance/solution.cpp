class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        
        // Rows: word1 (m+1), columns: word2 (n+1)
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        // First row: base case (word1 is empty, insert 
        // n elements to word1 to get word2)
        for (int c = 0; c <= n; ++c)
            dp[0][c] = c;
        
        // First column: base case (word2 is empty, delete
        // m elemenets from word1 to get word2)
        for (int r = 1; r <= m; ++r)
            dp[r][0] = r;
        
        // When the two characters, word1[r-1] and word2[c-1]
        // are equal, no operation required.
        // However, when the two characters are different, 
        // we consider three possible operations resulted
        // in the current scenario:
        //  from insert
        //      # of operations: dp[r, c-1] + 1
        //  from delete
        //      # of operations: dp[r-1, c] + 1
        //  from replace
        //      # of operations: dp[r-1, c-1]
        for (int r = 1; r <= m; ++r) {
            for (int c = 1; c <= n; ++c) {
                if (word1[r-1] == word2[c-1])
                    dp[r][c] = dp[r-1][c-1];
                else
                    dp[r][c] = min(dp[r-1][c], 
                                   min(dp[r][c-1], 
                                       dp[r-1][c-1])) + 1;
            }
        }
        
        return dp[m][n];
    }
};