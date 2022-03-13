class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        
        // Dynamic programming transfer function:
        //  dp[i] = dp[i-1],
        //              when only the current digit can be decoded
        //        = dp[i-1] + dp[i-2],
        //              when we can decode using one or two digits
        for (int i = 0; i < n; ++i) {
            // When the current position (i) can be decoded
            // using a single digit from 1 to 9
            if (s[i] != '0')
                dp[i+1] += dp[i];
            
            // When position i and i-1 can be decoded using
            // two digits from 1 to 26
            if (i >= 1 && s[i-1] != '0' && 
                (s[i-1]-'0')*10+(s[i]-'0') <= 26)
                dp[i+1] += dp[i-1];
        }
        
        return dp[n];
        
        // A more memory-efficient solution in solution2.cpp
    }
};