class Solution {
public:
    /* Dynamic programming (optimized) */
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        // For each step, we need to decide whether
        // or not to rob the current house.
        // If we rob the current house, we get
        // nums[i] + dp[i-2]. If we don't rob the
        // house, we get dp[i-1]. Therefore, the
        // recurrence relation is:
        // dp[i] = max(dp[i-1], nums[i-1] + dp[i-2])
        // Note that dp[0] is reserved for the
        // "house" left to the first house
        
        // Because there are only two states we need
        // to keep track of: 
        //  1. The total amount we robbed up until the
        //     the (i-2)-th house.
        //  2. The total amount we robbed up until the
        //     the (i-1)-th house.
        // Note: prev2 -> prev1 (prev1 is to the right
        // of prev2).
        int prev2 = 0, prev1 = nums[0], temp;
        for (int i = 1; i < n; ++i) {
            int temp = max(prev1, nums[i] + prev2);
            prev2 = prev1;
            prev1 = temp;
        }
        
        return prev1;
    }
};