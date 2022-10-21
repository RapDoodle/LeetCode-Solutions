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
            // current string results in a longer subset.
            // The recurrence equation is
            //  dp[i][j][k] = max(dp[i][j][k-1], 1 + dp[i-zeros][j-ones][k-1])
            // where k is the index of the string
            // Each loop must start from the end because
            // we are based on the results from the previous
            // string (the 2D dp array is compressed from 3D)
            for (int i = m; i >= zeros; --i)
                for (int j = n; j >= ones; --j)
                    dp[i][j] = max(dp[i][j], 1 + dp[i-zeros][j-ones]);
        }
        
        return dp[m][n];
    }
};