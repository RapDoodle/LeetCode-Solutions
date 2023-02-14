class Solution {
public:
    /* Hash map (vector) */
    int firstUniqChar(string s) {
        // The position of a character's
        // first occurrence. If a 
        // duplicate is found, set the
        // position as -1.
        int pos[26];
        for (int i = 0; i < 26; ++i)
            pos[i] = INT_MIN;
        
        // Set ASCII letters start at 0
        int n = s.length();
        for (int i = 0; i < n; ++i)
            s[i] -= 'a';

        // Create position index
        for (int i = 0; i < n; ++i)
            if (pos[s[i]] == INT_MIN)
                pos[s[i]] = i;
            else
                // Contains duplicate
                pos[s[i]] = -1;

        // Find the first unique character
        for (int i = 0; i < n; ++i)
            if (pos[s[i]] == i)
                return i;

        // Not found
        return -1;
    }
};