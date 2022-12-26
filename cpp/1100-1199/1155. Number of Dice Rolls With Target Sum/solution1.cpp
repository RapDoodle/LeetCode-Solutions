class Solution {
private:
    const int MOD = 1e9 + 7;

public:
    /* DP with Groupping */
    int numRollsToTarget(int n, int k, int target) {
        // Find the maximum possible target
        int maxTarget = n * k;
        if (maxTarget < target)
            return 0;
        
        vector<vector<int>>dp(n+1, vector<int>(target+1, 0));

        // Base case: There's only one way to reach a given
        // target with only once dice.
        for (int j = 1; j <= min(k, target); ++j)
            dp[1][j] = 1;

        // i is the number of dices, j is the current target.
        // Recurrence:
        //  dp[i, j] = dp[i, j-1] + dp[i, j-2] + ... + dp[i, j-k]
        // Interpretation: To each reach j with i dices from a 
        // target of j-x (x in [1..k]) with i-1 dices, there's 
        // only one way. For a dice with k faces, we consider the
        // sum over every single face.
        for (int i = 2; i <= n; ++i)
            for (int j = i; j <= target; ++j)
                for (int x = 1; x <= k && j-x > 0; ++x)
                    dp[i][j] = (dp[i][j] + dp[i-1][j-x]) % MOD;

        return dp[n][target];

        // A more memory efficient solution can be found in 
        // solution2.cpp
    }
};