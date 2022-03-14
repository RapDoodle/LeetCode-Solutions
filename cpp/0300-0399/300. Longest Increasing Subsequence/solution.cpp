class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), maxSeq = 1;
        vector<int> dp(n, 1);
        
        // For every interval [a, b], determine the 
        // longest increasing subsequence up until b
        for (int b = 0; b < n; ++b) {
            for (int a = 0; a < b; ++a)
                if (nums[a] < nums[b])
                    dp[b] = max(dp[b], dp[a] + 1);
            maxSeq = max(maxSeq, dp[b]);
        }
        
        return maxSeq;
    }
};