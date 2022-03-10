class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        
        // For example: [1,2,3,4,5,8,9,10,11,15]
        //  [1,2,3], [2,3,4], [3,4,5]
        //  [1,2,3,4], [2,3,4,5]
        //  [1,2,3,4,5]
        //  [8,9,10], [9,10,11]
        //  [8,9,10,11]
        //  => 3 + 2 + 1 + 2 + 1 = 9
        for (int i = 2; i < n; ++i)
            if (nums[i] - nums[i-1] == nums[i-1] - nums[i-2])
                dp[i] = dp[i-1] + 1;
        
        return accumulate(dp.begin(), dp.end(), 0);
        
        // A more memory-efficient solution in solution2.cpp
    }
};