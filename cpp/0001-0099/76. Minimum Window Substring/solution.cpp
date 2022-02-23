class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() == 0)
            return "";
        
        // Count the number of unique elements in t
        int required = 0;
        
        // A hash map for string t, with key being the char 
        // and value being the character's occurrence count
        unordered_map<char, int> tm; 
        
        for (char c : t) {
            if (tm.find(c) == tm.end()) {
                // The entry does not exist, create the entry
                tm[c] = 1;
                ++required;
            } else {
                ++tm[c];
            }
        }
        
        // A hash map for string s
        unordered_map<char, int> sm;
        int l = 0, minLen = 0, ansL = 0, match = 0;
        for (int r = 0; r < s.size(); ++r) {
            char rc = s[r];
            if (tm.find(rc) != tm.end()) {
                // Only consider the characters appeared in t
                if (sm.find(rc) == sm.end())
                    sm[rc] = 1;
                else
                    ++sm[rc];

                // When the number of characters required equals
                // the substring's count for the current character,
                // increment the match count
                if (sm[rc] == tm[rc])
                    ++match;
            }
            
            // When every character in sm is greater or equal to
            // the count in tm
            while (match == required) {
                int len = r - l + 1;
                
                // Update the minimum length is possible
                if (minLen == 0 || len < minLen) {
                    minLen = len;
                    ansL = l;
                }
                
                // Move the left pointer to look for a smaller 
                // substring
                char lc = s[l];
                if (tm.find(lc) != tm.end()) {
                    --sm[lc];
                    if (sm[lc] < tm[lc])
                        --match;
                }
                ++l;
            }
        }
        
        return s.substr(ansL, minLen);
    }
};