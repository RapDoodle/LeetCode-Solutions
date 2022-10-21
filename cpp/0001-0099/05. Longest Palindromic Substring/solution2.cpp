class Solution {
public:
    string longestPalindrome(const string& s) {
        if (s.empty() || s.length() < 1)
            return "";

        int m = s.length(), maxOfst = 0, l = 0;
        for (int i = 0; i < m; i++) {
            // Expand from the center
            // Two types of center:
            //   bab  baab
            //    ^    ^^
            int ofst = max(expand(s, i, i), expand(s, i, i+1));
            if (ofst > maxOfst) {
                maxOfst = ofst;
                l = i - ((ofst - 1) / 2);
            }
        }
        return s.substr(l, maxOfst);
    }
    
    int expand(const string& s, int l, int r) {
        if (s.empty() || l > r)
            return 0;
        int m = s.length();
        while (l >= 0 && r < m && s[l] == s[r]) {
            l--;
            r++;
        }
        return r - l - 1;
    }
};