class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        if (s[0] == '0')
            return 0;
        
        int dp = 0, prev1 = 1, prev2 = 0;
        // Dynamic programming transfer function:
        //  dp[i] = dp[i-1],
        //              when only the current digit can be decoded
        //        = dp[i-1] + dp[i-2],
        //              when we can decode using one or two digits
        for (int i = 0; i < n; ++i) {
            dp = 0;
            
            // When the current position (i) can be decoded
            // using a single digit from 1 to 9
            if (s[i] != '0')
                dp += prev1;
            
            // When position i and i-1 can be decoded using
            // two digits from 1 to 26
            if (i >= 1 && s[i-1] != '0' && 
                (s[i-1]-'0')*10+(s[i]-'0') <= 26)
                dp += prev2;
            
            prev2 = prev1;
            prev1 = dp;
        }
        
        return dp;
    }
};