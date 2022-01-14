class Solution {
public:
    /* A dynamic programming approach */
    bool isMatch(string s, string p) {
        // Initialize an array of size 
        // (s.length() + 1) * (p.length() + 1)
        int m = s.length() + 1, n = p.length() + 1;
        bool** dp = new bool* [m];
        for (int i = 0; i < m; i++) {
            dp[i] = new bool[n];
            for (int j = 0; j < n; j++)
                dp[i][j] = 0;
        }

        dp[0][0] = true;
        for (int i = 1; i < m; i++)
            dp[i][0] = false;

        // Do not have to worry about j-2 being out-of-bound:
        // the position of * is guranteed to be after a character
        // >= 2 (the first column is for the empty string)
        for (int j = 1; j < n; j++)
            if (p[j - 1] == '*')
                dp[0][j] = dp[0][j - 2];

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    // By default, 0 matches
                    dp[i][j] = dp[i][j - 2];
                    // Match the previous occurrence. For example, 
                    // the a in a*. or any character in .*
                    // Then, either the default case or the matching
                    // case is true, the result is true
                    if (s[i - 1] == p[j - 2] || p[j - 2] == '.')
                        dp[i][j] = dp[i - 1][j] | dp[i][j];
                } else {
                    dp[i][j] = false;
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};