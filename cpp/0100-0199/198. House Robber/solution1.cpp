class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0);
        
        // For each step, we need to decide whether
        // or not to rob the current house.
        // If we rob the current house, we get
        // nums[i] + dp[i-2]. If we don't rob the
        // house, we get dp[i-1]. Therefore, the
        // transfer function is:
        // dp[i] = max(dp[i-1], nums[i-1] + dp[i-2])
        vector<int> dp(n+1, 0);
        
        // dp[0] = 0 because there isn't a house to
        // the left of house 0. Robbing such an 
        // invalid house only gets an amount of 0.
        // dp[1] represents the money we can get by
        // robbing the first house. 
        dp[1] = nums[0];
        for (int i = 2; i <= n; ++i) {
            // Notice the i is for the dp array, which
            // has a size of n+1. Therefore, we need to 
            // use i-1 to access the nums array.
            dp[i] = max(dp[i-1], nums[i-1] + dp[i-2]);
        }
        
        return dp[n];
        
        // See a more memory-efficient algorithm in
        // solution2.cpp
    }
};