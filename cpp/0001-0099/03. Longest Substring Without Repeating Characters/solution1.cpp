class Solution {
public:
    /* Hash map */
    int lengthOfLongestSubstring(string s) {
        // Use a hash map to store where a character 
        // was last seen. Iterate through characters
        // in the string. If the current character
        // is found within the current interval,
        // update the interval to start after the 
        // previous occurrence.
        unordered_map<char, int> cnt;
        int currLen = 0, maxLen = 0, n = s.length();
        for (int i = 0; i < n; ++i) {
            if ((cnt.find(s[i]) != cnt.end() && i - currLen > cnt[s[i]])
                || cnt.find(s[i]) == cnt.end()) {
                // No duplicate character found within
                // the current interval
                ++currLen;
                maxLen = max(maxLen, currLen);
            } else {
                // Found a duplicate, trim the interval
                currLen = i - cnt[s[i]];
            }
            cnt[s[i]] = i;
        }
        return maxLen;
    }
};