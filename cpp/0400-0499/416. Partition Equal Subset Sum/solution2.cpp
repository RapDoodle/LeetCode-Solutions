class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        // Odd numbers cannot be divided into equal halves
        if (sum % 2 != 0)
            return false;
        
        // Equivalent to a 0-1 knapsack problem. Goal:
        // Select a subset of integers to form a partition that 
        // equals to the target value. Because we do not 
        // consider the value, using a vector of type boolean
        // would suffice the purpose.
        int target = sum / 2, n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(target+1, false));
        dp[0][0] = true;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= target; ++j) {
                if (j < nums[i-1])
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
            }
        }
        
        return dp[n][target];
    }
};