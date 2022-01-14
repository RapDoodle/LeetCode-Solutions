class Solution {
public:
    /* Dynamic programming */ 
    string longestPalindrome(string s) {
        int m = s.length(), lo = 0, maxLen = 1;

        // Initialize an array of size m * m
        int** dp = new int* [m];
        for (int i = 0; i < m; i++)
            dp[i] = new int[m];

        // Fill all diagonal with 1
        for (int i = 0; i < m; i++)
            dp[i][i] = 1;

        // Check for substrings of length > 2
        int valid = 0, j = 0;
        for (int ofst = 1; ofst < m; ++ofst) {
            for (int i = 0; i < m - ofst; ++i) {
                j = i + ofst;
                if (ofst == 1)
                    valid = dp[i][j] = s[i] == s[j] ? 1 : 0;
                else
                    valid = dp[i][j] = (s[i] == s[j] && dp[i+1][j-1] == 1) ? 1 : 0;
                if (valid) {
                    int length = ofst + 1;
                    if (length > maxLen) {
                        maxLen = length;
                        lo = i;
                    }
                }
            }
        }
        return s.substr(lo, maxLen);
    }
};