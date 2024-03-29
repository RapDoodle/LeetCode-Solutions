class Solution {
public:
    /* Dynamic programming */
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        // Odd numbers cannot be divided into equal halves
        if (sum % 2 != 0)
            return false;
        
        // Calculate the target (should be an even number)
        int target = sum / 2, n = nums.size();

        // Dynamic programming.
        vector<vector<bool>> dp(nums.size()+1, vector<bool>(target+1, false));

        // Boundary condition: The subset of an empty set can reach a sum of 0
        dp[0][0] = true;

        // Similar to a Knapsack problem. At each step, consider whether or not
        // include the current element. The recurrence is:
        //  dp[i, j] = dp[i-1, j] || dp[i-1, j-nums[i]] when j >= nums[i]
        //             dp[i][j] = dp[i-1][j] when otherwise
        for (int i = 1; i <= nums.size(); ++i) {
            for (int j = 1; j <= target; ++j)
                // Note: i-1 is to account for the offset that the first element
                // in the DP array starts at 1.
                if (j >= nums[i-1])
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
                else
                    dp[i][j] = dp[i-1][j];
            // Return immediately once once a subset can reach the target
            if (dp[i][target])
                return true;
        }
        return false;
    }
};