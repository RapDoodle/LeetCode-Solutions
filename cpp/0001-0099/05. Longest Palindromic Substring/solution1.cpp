class Solution {
public:
    /* Dynamic programming */ 
    string longestPalindrome(const string& s) {
        int m = s.length(), lo = 0, maxLen = 1;

        // Initialize an array of size m * m
        vector<vector<int>> dp(m, vector<int>(m));

        // Fill all diagonals with 1
        for (int i = 0; i < m; ++i)
            dp[i][i] = 1;

        // Check for substrings of length > 2
        for (int strOfst = 1; strOfst < m; ++strOfst) {
            for (int i = 0; i < m - strOfst; ++i) {
                // Calculate the upper bound of the substring
                int j = i + strOfst;
                // Check the two ends of the interval. 
                // If the two ends equal (s[i] == s[j]), 
                // and the substring in the middle 
                // [i+1..j-1] is also a palindrome,
                // [i..j] is also a palindrome
                if (strOfst == 1)
                    dp[i][j] = (s[i] == s[j] ? 1 : 0);
                else
                    dp[i][j] = (s[i] == s[j] && dp[i+1][j-1] == 1) ? 1 : 0;
                if (dp[i][j]) {
                    int length = strOfst + 1;
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