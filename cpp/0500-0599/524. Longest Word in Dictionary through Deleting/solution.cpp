class Solution {
public:
    /* Greedy, two-pointers */
    string findLongestWord(string s, vector<string>& dictionary) {
        // After sorting, longer words should come first. In case two 
        // strings have the same length, the word with the smaller 
        // lexicographical order comes first. E.g., "aa" < "ab", 
        // "aa" should come first
        sort(dictionary.begin(), dictionary.end(), [](string& a, string& b) {
            return a.length() != b.length() ? a.length() > b.length() : a < b;
        });
        
        for (auto w : dictionary) {
            // Check if d can be formed by elements of s
            int i = 0, j = 0;
            while (i < w.length() && j < s.length()) {
                if (w[i] == s[j])
                    ++i;
                ++j;
            }
            
            if (i == w.length())
                return w;
        }
        
        return "";
    }
};