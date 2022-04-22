class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // Mappings from the original character
        // to the new character.
        // m1: from s to t, m2: from t to s
        unordered_map<char, char> m1, m2;
        for (int i = 0; i < s.length(); ++i) {
            char cs = s[i], ct = t[i];
            if (m1.find(cs) != m1.end() && m1[cs] != ct ||
                m2.find(ct) != m2.end() && m2[ct] != cs)
                return false;
            m1[cs] = ct;
            m2[ct] = cs;
        }
        
        return true;
    }
};