class Solution {
public:
    /* The brute force approach:
     * Time complexity: O(n * m)
     * Space complexity: O(1)
     */
    int strStr(string haystack, string needle) {
        if (needle.length() == 0)
            return 0;
        
        int i = 0, j = 0;
        while (i < haystack.length() && j < needle.length()) {
            if (haystack[i] == needle[j])
                ++j;
            else if (j > 0) {
                i -= j;
                j = 0;
            }
            ++i;
        }
        
        if (j == needle.length())
            return i - needle.length();
        else
            return -1;
    }
};