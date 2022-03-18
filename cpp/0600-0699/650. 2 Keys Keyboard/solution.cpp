class Solution {
public:
    int minSteps(int n) {
        // For each position, copy for once and
        // keep on pasting before exceeding the
        // required length n, take the minimum
        // at each step.
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            // NOTE: The clipboard size is i
            // One operation for copy
            int step = dp[i-1] + 1;
            for (int j = i + i; j <= n; j += i) {
                // One operation for each paste
                dp[j-1] = min(dp[j-1], ++step);
            }
        }
        
        return dp[n-1];
    }
};