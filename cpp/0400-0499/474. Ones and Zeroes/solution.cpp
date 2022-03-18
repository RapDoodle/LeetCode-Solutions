class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        // A 2D 0-1-Knapsack problem: rows for the number
        // of zeros and columns for the number of ones.
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for (const string& str : strs) {
            int zeros = 0, ones = 0;
            for (const char& c : str)
                if (c == '0')
                    ++zeros;
                else
                    ++ones;
            
            // For each valid position, check if adding the
            // current string results in a longer subset
            for (int i = m; i >= zeros; --i)
                for (int j = n; j >= ones; --j)
                    dp[i][j] = max(dp[i][j], 1 + dp[i-zeros][j-ones]);
        }
        
        return dp[m][n];
    }
};