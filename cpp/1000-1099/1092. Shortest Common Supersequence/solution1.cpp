class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        // Find the longest common subsequence
        int m = str1.length(), n = str2.length();
        str1 = " " + str1;
        str2 = " " + str2;
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= n; ++j)
                if (str1[i] == str2[j])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else 
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        
        // Construct the SCS (reversed)
        string scs = "";
        int i = m, j = n;
        while (i > 0 || j > 0) {
            if (i == 0) {
                // Add the remaining characters in str2
                scs += str2[j--];
            } else if (j == 0) {
                // Add the remaining characters in str1
                scs += str1[i--];
            } else {
                if (str1[i] == str2[j]) {
                    scs += str1[i];
                    i--;
                    j--;
                } else {
                    if (dp[i-1][j] >= dp[i][j-1]) {
                        // Came from the top
                        scs += str1[i--];
                    } else {
                        // Came from the left
                        scs += str2[j--];
                    }
                }
            }
        }
        
        reverse(scs.begin(), scs.end());
        return scs;
    }
};