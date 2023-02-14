class Solution {
public:
    /* Hash map */
    int firstUniqChar(string s) {
        // The position of a character's
        // first occurrence. If a 
        // duplicate is found, set the
        // position as -1.
        unordered_map<char, int> pos;

        // Create position index
        int n = s.length();
        for (int i = 0; i < n; ++i)
            if (pos.find(s[i]) == pos.end())
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