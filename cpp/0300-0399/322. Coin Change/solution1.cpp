class Solution {
public:
    /* Dynamic programming */
    int coinChange(vector<int>& coins, int amount) {
        // For each value in [1..amount], determine 
        // whether adding the current coin reduces
        // the totoal number of coins needed.
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            // For each subproblem, we find the minimum
            // number of coins required for a total 
            // amount of i, where i <= amount
            for (auto const& coin : coins) {
                int diff = i-coin;
                if (diff >= 0)
                    dp[i] = min(dp[i], dp[diff] + 1);
            }
        }
        
        // If the final value is greater than the amount
        // defined, it means the value is unchanged
        // due to there's no suitable coin for the
        // last step (possibly more steps). In such 
        // cases, return -1 as required.
        return dp[amount] <= amount ? dp[amount] : -1;
    }
};