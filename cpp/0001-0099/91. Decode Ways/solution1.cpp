class Solution {
public:
    /* Dynamic programming */
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        
        // Recurrence:
        //  dp[i] = dp[i-1],
        //              when only the current digit can be decoded
        //        = dp[i-2],
        //              when we can only decode using two digits
        //        = dp[i-1] + dp[i-2],
        //              when we can decode using one or two digits
        for (int i = 0; i < n; ++i) {
            // When the current position (i) can be decoded
            // using a single digit from 1 to 9
            if (s[i] != '0')
                dp[i+1] += dp[i];
            
            // When position i and i-1 can form an integer between
            // 1 and 26
            if (i >= 1 && (s[i-1] == '1' || (s[i-1] == '2' && s[i] >= '0' && s[i] <= '6')))
                dp[i+1] += dp[i-1];
        }
        
        return dp[n];
        
        // A more memory-efficient solution in solution2.cpp
    }
};