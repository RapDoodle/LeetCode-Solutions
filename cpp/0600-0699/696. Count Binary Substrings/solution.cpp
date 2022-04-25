class Solution {
public:
    int countBinarySubstrings(string s) {
        // Group digits
        int count = 0, prev = 0, curr = 1;
        for (int i = 1; i < s.length(); ++i) {
            if (s[i-1] == s[i]) {
                ++curr;
            } else {
                // At the beginning of the i-th group,
                // count the number of possible substrings
                // in the (i-1)-th and (i-2)-th group.
                // For adjacent groups, the number of 
                // substring are the minimum of the two
                // For example: 0001, then the number of
                // possible substring(s) = min(3, 1) = 1
                count += min(curr, prev);
                prev = curr;
                curr = 1;
            }
        }
        // Add the last group
        count += min(curr, prev);
        return count;
    }
};