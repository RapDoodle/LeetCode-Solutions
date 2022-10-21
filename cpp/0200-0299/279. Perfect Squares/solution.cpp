class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, n);
        
        // We keep it here because we need to ensure when 
        // i = n, we have i-j*j, which MAY result in 
        // n-sqrt(n)^2 = 0.
        dp[0] = 0;
        
        // For each subproblem, we wish to solve the least
        // number of perfect sqaure numbers that sum
        // to i, where i <= n
        for (int i = 1; i <= n; ++i) {
            // To solve the subproblem, we need to find
            //  min(dp[i-1], dp[i-2], dp[i-4], ...) + 1,
            // which is the number of perfect squares 
            // needed to reach i
            for (int j = 1; j*j <= i; ++j) 
                dp[i] = min(dp[i], dp[i-j*j]);
            ++dp[i];
            // For example, when n = 12.
            //  When i = 1, dp[1] = 1
            //      min(dp[1-1*1]=dp[0]=0) + 1 = 1
            //  When i = 2, dp[2] = 2
            //      min(dp[2-1*1]=dp[1]=1) + 1 = 2
            //  When i = 3, dp[3] = 3
            //      min(dp[3-1*1]=dp[2]=2) + 1 = 3
            //  When i = 4, dp[4] = 1 
            //      min(dp[4-1*1]=dp[3]=3
            //          dp[4-2*2]=dp[0]=0) + 1 = 1
            //  ...
            //  When i = 8, dp[8]=2
            //      min(dp[8-1*1]=dp[7]=4,
            //          dp[8-2*2]=dp[4]=1) + 1 = 2
            //  ...
            //  When i = 12, dp[12]=3 
            //      min(dp[12-1*1]=dp[11]=3,
            //          dp[12-2*2]=dp[8]=2
            //          dp[12-3*3]=dp[3]=3) + 1 = 3
            // Trancing back, we get
            //  dp[12] = 3
            //  dp[12-2*2] = dp[8] = 2
            //  dp[8-2*2] = dp[4] = 1
            //  dp[4-2*2] = dp[0] = 0
            // Thus, 12 = 4 + 4 + 4
        }
        
        return dp[n];
    }
};