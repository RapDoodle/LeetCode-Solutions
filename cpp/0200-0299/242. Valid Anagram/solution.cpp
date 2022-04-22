class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;
        
        unordered_map<char, int> m;
        for (int i = 0; i < s.length(); ++i) {
            ++m[s[i]-'a'];
            --m[t[i]-'a'];
        }
        
        // Every key should have a value of 0
        for(const auto &kv : m) {
            if (kv.second != 0)
                return false;
        }
        return true;
    }
};