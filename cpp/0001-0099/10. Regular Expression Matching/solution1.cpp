class Solution {
public:
    /* Dynamic Programming */
    bool isMatch(string s, string p) {
        // Initialize an array of size 
        // (s.length() + 1) * (p.length() + 1)
        int m = s.length() + 1, n = p.length() + 1;
        vector<vector<bool>> dp(m, vector<bool>(n, false));

        dp[0][0] = true;
        for (int i = 1; i < m; ++i)
            dp[i][0] = false;

        // Special case: pattern containing "*" matching with an 
        // empty string.
        // Start from 2 because a "*" is guranteed to be after a 
        // character (the first column is represents empty string)
        for (int j = 2; j < n; ++j)
            if (p[j-1] == '*')
                dp[0][j] = dp[0][j-2];

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (s[i-1] == p[j-1] || p[j-1] == '.') {
                    // A match
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j-1] == '*') {
                    // 0 occurence of p[j-2] ("*" is not used).
                    dp[i][j] = dp[i][j-2];

                    // Match the previous occurrence. For example, 
                    // the "a" (which is p[j-2]) in "a*." 
                    // or any character "." (also p[j-2]) for ".*"
                    // Then, either the default case or the matching
                    // case is true, the result will be true
                    if (s[i-1] == p[j-2] || p[j-2] == '.')
                        dp[i][j] = dp[i-1][j] || dp[i][j];
                } else {
                    // Not a match
                    dp[i][j] = false;
                }
            }
        }

        return dp[m-1][n-1];
    }
};