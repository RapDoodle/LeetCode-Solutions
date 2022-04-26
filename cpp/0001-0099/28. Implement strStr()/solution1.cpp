class Solution {
public:
    /* The KMP algorithm approach:
     * Time complexity: O(n + m)
     * Space complexity: O(m)
     */
    int strStr(string haystack, string needle) {
        // KMP algorithm explanation:
        // https://www.youtube.com/watch?v=V5-7GzOfADQ
        int n = haystack.length(), m = needle.length();
        
        // Generate the needle's pi-table
        vector<int> pi(m, 0);
        for (int i = 0, j = 1; j < m; ++j) {
            // i is the slow-moving pointer and 
            // j is the fast-moving pointer. 
            while (i > 0 && needle[i] != needle[j])
                // A mismatch. Keep looping until a match
                // is found. Use the previously matched
                // value.
                i = pi[i - 1];
            
            if (needle[i] == needle[j])
                // A match. Move the slow-moving pointer
                ++i;
            
            // Hint the algorithm that when there is a 
            // mismatch at position j, in the next step,
            // check the i-th position of the needle 
            // instead of starting from the beginning.
            pi[j] = i;
        }
        
        // Iterate through the haystack
        for (int i = 0, j = 0; j < n; ++j) {
            while (i > 0 && needle[i] != haystack[j])
                // In case of a mismatch, rewind to the 
                // hinted location
                i = pi[i - 1];
            
            if (needle[i] == haystack[j])
                // A match, move the fast-moving pointer
                // to the right
                ++i;
            
            if (i == m)
                // Reached the end of the needle, return
                // the beginning index of the substring
                return j - m + 1;
        }
        
        // No match found
        return -1;
    }
};