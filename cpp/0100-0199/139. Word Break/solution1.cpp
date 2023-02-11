class Solution {
public:
    /* Dynamic programming */
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        
        // Recurrence:
        //  dp[i] = dp[i-len], when s[i-len, i] is in wordDict
        //        = false, when s[i-len, i] is not in wordDict
        //        = true, when i=0 (the initial state)
        vector<bool> dp(n+1, false);
        dp[0] = true;
        for (int i = 1; i <= n; ++i) {
            for (const auto& word : wordDict) {
                int len = word.length();
                if (i >= len && s.substr(i-len, len) == word && dp[i-len])
                    dp[i] = true;
            }
        }
        
        return dp[n];
    }
};